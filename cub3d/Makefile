# paths
vpath %.c srcs/parsing
vpath %.c srcs/parsing/extension
vpath %.c srcs/parsing/colors
vpath %.c srcs/parsing/map
vpath %.c srcs/parsing/texture
vpath %.c srcs/utils/parsing_utils
vpath %.c srcs/parsing/map/bonus
vpath %.c srcs/parsing/texture vpath 
vpath %.c srcs/utils/parsing_utils
vpath %.c srcs/utils
vpath %.c srcs/events
vpath %.c srcs/objects
vpath %.c srcs/map
vpath %.c srcs/setup
vpath %.c srcs/player
vpath %.c srcs/raycast
vpath %.c srcs/floor_and_ceiling

#vpath %.c debug

BUILD_DR = ./build/
NAME = cub3D

LIBFT_DR = ./libft
LIBFT = -L$(LIBFT_DR) -lft
INCLUDES_DRS = -I./includes -I./libft/includes 
HEADERS = ./includes/colors.h ./includes/floor_and_ceiling.h ./includes/objects.h ./includes/parsing.h ./includes/raycast.h ./includes/setup.h ./includes/player.h ./includes/utils.h ./includes/container.h ./includes/events.h ./includes/settings.h ./includes/types.h ./includes/map.h
FLAGS = -Wall -Wextra -Werror #-g #-fsanitize=address  #-g3 #

INCLUDES_DRS = -I./includes -I./libft/includes
CC = cc
RM = rm -f

# srcs
F_UTILS = rewirte_mlx.c free_methods.c handel_exit.c \
		  cleanup.c helper_fun.c init_cub_data.c convert_map.c is_wall.c color_methods.c \
			mouse_utils.c door_methods.c ft_time_now.c
F_EVENTS = destroy.c loop.c  key_hook.c mouse.c
F_OBJECTS = render_rec.c render_cercle.c  render_line.c render_aim.c
F_MAP = map.c
F_PLAYER = player.c events_handler.c animation.c
F_SETUP = setup.c load_textures.c
F_RAYCAST = raycast.c wall_check.c textures.c
F_FLOOR_AND_CEILING = render_fc.c
F_PARSING = color_parsing.c color_validation.c \
			map_parsing.c  map_validation.c  map_validation2.c player_validation.c \
			text_parsing.c text_validation.c \
			extension_validation.c texture_extension_validation.c  map_bonus_validation.c bonus_validation_helper.c \
			parsing.c 

#F_DEBUG = map_utils3.c map_utils.c parsing_debug.c print_t_player_type.c print_2d_arr.c create_fake_pars_info.c
SRCS= main.c $(F_UTILS) $(F_SETUP) $(F_PLAYER) $(F_EVENTS) $(F_OBJECTS) $(F_MAP) $(F_PARSING) $(F_RAYCAST) $(F_FLOOR_AND_CEILING)
OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))

# colors
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(BUILD_DR)%.o: %.c $(HEADERS) | $(BUILD_DR) 
	$(CC) $(FLAGS) $(INCLUDES_DRS) -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DR)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) $(LIBFT)  -lmlx -lXext -lX11 -lm -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
