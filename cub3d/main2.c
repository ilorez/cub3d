// demo_mouse_look.c
// MiniLibX demo: grid pattern + mouse lock on enter + camera with mouse + center crosshair.

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <X11/extensions/Xfixes.h>
#include <wchar.h>
#include "../../../home/znajdaou/Desktop/Cub3d-Linux/minilibx-linux/mlx_int.h"

// ---------- platform keys ----------
#ifdef __APPLE__
#  define KEY_ESC 53
#else
#  define KEY_ESC 65307
#endif

// ---------- X11 event codes & masks ----------
#define ON_KEYDOWN      2
#define ON_KEYUP        3
#define ON_MOUSEDOWN    4
#define ON_MOUSEUP      5
#define ON_MOUSEMOVE    6
#define ON_ENTER        7
#define ON_EXPOSE       12
#define ON_DESTROY      17

#define MASK_KEYPRESS           (1L<<0)
#define MASK_KEYRELEASE         (1L<<1)
#define MASK_BUTTONPRESS        (1L<<2)
#define MASK_BUTTONRELEASE      (1L<<3)
#define MASK_POINTERMOTION      (1L<<6)
#define MASK_ENTERWINDOW        (1L<<4)

// ---------- weak MLX mouse helpers (not all forks have them) ----------
//int mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y) __attribute__((weak));
//int mlx_mouse_hide(void *mlx_ptr, void *win_ptr) __attribute__((weak));
//int mlx_mouse_show(void *mlx_ptr, void *win_ptr) __attribute__((weak));


#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

// ---------- types ----------
typedef struct s_imgg {
    void    *ptr;
    char    *addr;
    int     bpp;
    int     ll;
    int     endian;
    int     w, h;
} t_imgg;

typedef struct s_mouse {
    int     grabbed;        // cursor locked?
    int     warp_supported; // mlx_mouse_move available?
    int     warp_guard;     // ignore next motion (caused by warp)
    double  yaw_sens;       // radians per pixel (left/right)
    double  move_sens;      // world units per pixel (up/down)
    double  dx_accum;       // accumulated horizontal delta
    double  dy_accum;       // accumulated vertical delta
} t_mouse;

typedef struct s_cam {
    double  x, y;           // position in world
    double  ang;            // facing angle (radians)
} t_cam;

typedef struct s_app {
    void    *mlx;
    void    *win;
    int     w, h;
    t_imgg   frame;
    t_cam   cam;
    t_mouse mouse;
    int     running;
} t_app;

// ---------- img helpers ----------
static int in_bounds(t_imgg *img, int x, int y) {
    return (x >= 0 && y >= 0 && x < img->w && y < img->h);
}

static void put_px(t_imgg *img, int x, int y, uint32_t argb) {
    if (!in_bounds(img, x, y)) return;
    char *dst = img->addr + y * img->ll + x * (img->bpp / 8);
    *(uint32_t *)dst = argb;
}

static void clear_imgg(t_imgg *img, uint32_t argb) {
    int px = img->w * img->h;
    uint32_t *p = (uint32_t *)img->addr;
    for (int i = 0; i < px; ++i) p[i] = argb;
}

// ---------- crosshair ----------
static void draw_crosshair(t_imgg *img, int cx, int cy) {
    const int len = 12;      // half-length of each line
    const int gap = 4;       // small center gap
    const int thick = 2;     // line thickness
    uint32_t c = 0xFFFFFFFF; // white
    // horizontal
    for (int t = -thick/2; t <= thick/2; ++t) {
        for (int x = cx - len; x <= cx - gap; ++x) put_px(img, x, cy + t, c);
        for (int x = cx + gap; x <= cx + len; ++x) put_px(img, x, cy + t, c);
    }
    // vertical
    for (int t = -thick/2; t <= thick/2; ++t) {
        for (int y = cy - len; y <= cy - gap; ++y) put_px(img, cx + t, y, c);
        for (int y = cy + gap; y <= cy + len; ++y) put_px(img, cx + t, y, c);
    }
}

// ---------- camera math ----------
static void dir_from_angle(double ang, double *dx, double *dy) {
    *dx = cos(ang);
    *dy = sin(ang);
}

// ---------- rendering a rotated/transformed checker grid ----------
// We render per-pixel: for each screen pixel, compute the inverse transform
// to world space (rotate by -ang, translate by cam (x,y)), then choose color
// based on which tile (i,j) we are in. Simple and very clear.
static void render_grid(t_app *a) {
    t_imgg *img = &a->frame;

    const int   tile = 64;                  // world-space tile size
    const double zoom = 1.0;                // screen px per world unit
    const int   cx = a->w / 2;
    const int   cy = a->h / 2;

    double ca = cos(-a->cam.ang), sa = sin(-a->cam.ang);

    // background color (subtle dark)
    clear_imgg(img, 0xFF202124);

    for (int y = 0; y < a->h; ++y) {
        double sy = (y - cy) / zoom;
        for (int x = 0; x < a->w; ++x) {
            double sx = (x - cx) / zoom;

            // rotate screen-space offset by -angle to get camera-aligned offset
            double rx = sx * ca - sy * sa;
            double ry = sx * sa + sy * ca;

            // world position = camera position + rotated offset
            double wx = a->cam.x + rx;
            double wy = a->cam.y + ry;

            int ti = (int)floor(wx / tile);
            int tj = (int)floor(wy / tile);
            int parity = (ti + tj) & 1;

            // two tile colors; add a tiny edge highlight for visual crispness
            uint32_t col = parity ? 0xFF2F3237 : 0xFF3A3E44;

            // edge highlight: draw thin lines at tile boundaries
            double fx = fabs(fmod(wx, tile));
            double fy = fabs(fmod(wy, tile));
            if (fx < 1.2 || fx > tile - 1.2 || fy < 1.2 || fy > tile - 1.2)
                col = 0xFF585D66;

            put_px(img, x, y, col);
        }
    }

    // center crosshair
    draw_crosshair(img, cx, cy);
}

// ---------- mouse grab/release ----------
static void grab_mouse(t_app *a) {
    a->mouse.grabbed = 1;
    if (a->mouse.warp_supported) mlx_mouse_hide(a->mlx, a->win);
    if (a->mouse.warp_supported) {
        mlx_mouse_move(a->mlx, a->win, a->w/2, a->h/2);
        a->mouse.warp_guard = 1;
    }
}

static void release_mouse(t_app *a) {
    a->mouse.grabbed = 0;
    if (a->mouse.warp_supported) mlx_mouse_show(a->mlx, a->win);
}

// ---------- event handlers ----------
static int on_keydown(int key, t_app *a) {
    if (key == KEY_ESC) {
        // ESC unlocks the mouse; press ESC again to exit, or close the window.
        if (a->mouse.grabbed) {
            release_mouse(a);
        } else {
            a->running = 0; // quit if not grabbed
        }
    }
    return 0;
}

static int on_destroy(t_app *a) {
    (void)a;
    exit(0);
    return 0;
}

static int on_enter(t_app *a) {
    // Lock as soon as the mouse enters the window
    printf("mouse enter: %s\n", a->mouse.grabbed ? "true": "false");
    if (!a->mouse.grabbed) grab_mouse(a);
    return 0;
}

static int on_mousemove(int x, int y, t_app *a) {
    if (a->mouse.warp_guard) { a->mouse.warp_guard = 0; return 0; }

    if (a->mouse.grabbed && a->mouse.warp_supported ) {
        int cx = a->w / 2, cy = a->h / 2;
        int dx = x - cx;
        int dy = y - cy;

        // clamp & deadzone
        if (dx > 1000) dx = 1000; else if (dx < -1000) dx = -1000;
        if (dy > 1000) dy = 1000; else if (dy < -1000) dy = -1000;
        if (dx > -1 && dx < 1) dx = 0;
        if (dy > -1 && dy < 1) dy = 0;

        a->mouse.dx_accum += dx;
        a->mouse.dy_accum += dy;

        // re-center so the pointer never escapes
        mlx_mouse_move(a->mlx, a->win, cx, cy);
        a->mouse.warp_guard = 1;
    } else {
        // fallback: absolute deltas (limited when hitting window edges)
        static int last_set = 0, last_x = 0, last_y = 0;
        if (!last_set) { last_x = x; last_y = y; last_set = 1; return 0; }
        a->mouse.dx_accum += (x - last_x);
        a->mouse.dy_accum += (y - last_y);
        last_x = x; last_y = y;
    }
    return 0;
}

// ---------- per-frame update ----------
static void apply_mouse_control(t_app *a) {
    // consume accumulated deltas once per frame
    double dx = a->mouse.dx_accum; a->mouse.dx_accum = 0.0;
    double dy = a->mouse.dy_accum; a->mouse.dy_accum = 0.0;

    if (dx != 0.0) a->cam.ang += dx * a->mouse.yaw_sens;

    // keep angle in [0, 2π)
    if (a->cam.ang >= 2.0*M_PI) a->cam.ang -= 2.0*M_PI;
    else if (a->cam.ang < 0.0) a->cam.ang += 2.0*M_PI;

    // move forward/back along facing direction based on vertical mouse motion
    if (dy != 0.0) {
        double fx, fy; dir_from_angle(a->cam.ang, &fx, &fy);
        double step = -dy * a->mouse.move_sens; // up = forward, down = backward
        a->cam.x += fx * step;
        a->cam.y += fy * step;
    }
}

static int on_loop(t_app *a) {
    if (!a->running) exit(0);

    apply_mouse_control(a);
    render_grid(a);

    mlx_put_image_to_window(a->mlx, a->win, a->frame.ptr, 0, 0);
    return 0;
}

// ---------- init ----------
static void init_app(t_app *a, int w, int h) {
    a->w = w; a->h = h;
    a->mlx = mlx_init();
    if (!a->mlx) exit(1);
    a->win = mlx_new_window(a->mlx, a->w, a->h, "MLX Mouse-Look Grid");
    if (!a->win) exit(1);

    a->frame.ptr = mlx_new_image(a->mlx, a->w, a->h);
    a->frame.addr = mlx_get_data_addr(a->frame.ptr, &a->frame.bpp, &a->frame.ll, &a->frame.endian);
    a->frame.w = a->w; a->frame.h = a->h;

    a->cam.x = 0.0; a->cam.y = 0.0; a->cam.ang = 0.0;

    a->mouse.grabbed = 0;
    a->mouse.warp_supported = 1;
    a->mouse.warp_guard = 0;
    a->mouse.dx_accum = 0.0;
    a->mouse.dy_accum = 0.0;
    a->mouse.yaw_sens  = 0.003; // try 0.002 .. 0.006
    a->mouse.move_sens = 0.08;  // world units per pixel (try 0.05 .. 0.15)

    a->running = 1;

    // event hooks
    mlx_hook(a->win, ON_KEYDOWN,   MASK_KEYPRESS,     on_keydown,  a);
    mlx_hook(a->win, ON_MOUSEMOVE, MASK_POINTERMOTION,on_mousemove, a);
    mlx_hook(a->win, ON_ENTER,     MASK_ENTERWINDOW,  on_enter,    a);
    mlx_hook(a->win, ON_DESTROY,   0,                 on_destroy,  a);

    // per-frame hook
    mlx_loop_hook(a->mlx, on_loop, a);

    // immediately grab so the pointer locks as soon as the window appears
    grab_mouse(a);
}

int main(void) {
    t_app *app;
    app = malloc(sizeof(t_app));
    init_app(app, 1024, 640);
    mlx_loop(app->mlx);
    return 0;
}

