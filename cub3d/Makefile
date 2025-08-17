# paths
vpath %.c srcs/parsing
vpath %.c srcs/parsing/extension
vpath %.c srcs/parsing/colors
vpath %.c srcs/parsing/map
vpath %.c srcs/parsing/texture
vpath %.c srcs/utils/parsing_utils

vpath %.c srcs/utils
vpath %.c srcs/events
vpath %.c srcs/objects
vpath %.c srcs/map
vpath %.c srcs/setup
vpath %.c srcs/player
vpath %.c srcs/raycast
vpath %.c srcs/floor_and_ceiling
vpath %.c debug
BUILD_DR = ./build/
NAME = cub3d

LIBFT_DR = ./libft
LIBFT = -L$(LIBFT_DR) -lft
INCLUDES_DRS = -I./includes -I./libft/includes 
HEADERS = ./includes/setup.h ./includes/player.h ./includes/utils.h ./includes/container.h ./includes/events.h ./includes/settings.h ./includes/types.h ./includes/map.h
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address #-g3 #

INCLUDES_DRS = -I./includes -I./libft/includes
CC = cc
RM = rm -f

# srcs
F_UTILS = rewirte_mlx.c free_methods.c handel_exit.c \
		  cleanup.c helper_fun.c init_cub_data.c convert_map.c is_wall.c color_methods.c
F_EVENTS = destroy.c loop.c  key_hook.c mouse_click.c
F_OBJECTS = render_rec.c render_cercle.c  render_line.c 
F_MAP = map.c
F_DEBUG = map_utils3.c map_utils.c parsing_debug.c 
F_PLAYER = player.c
F_SETUP = setup.c
F_RAYCAST = raycast.c wall_check.c
F_FLOOR_AND_CEILING = render_fc.c
F_PARSING = color_parsing.c color_validation.c \
			map_parsing.c  map_validation.c  map_validation2.c player_validation.c \
			text_parsing.c text_validation.c \
			extension_validation.c map_bonus_validation.c \
			parsing.c 

SRCS= main.c $(F_SETUP) $(F_PLAYER) $(F_DEBUG) $(F_UTILS) $(F_EVENTS) $(F_OBJECTS) $(F_MAP) $(F_PARSING) $(F_RAYCAST) $(F_FLOOR_AND_CEILING)
OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))

# colors
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(BUILD_DR)%.o: %.c $(HEADERS) | $(BUILD_DR) 
	$(CC) $(FLAGS) $(INCLUDES_DRS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DR)
	# this is for my laptop compilation 
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) $(LIBFT) -L/usr/lib -lmlx -lXext -lX11 -lm -o $(NAME)
	# for u uncomment this 
	# $(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm  -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
