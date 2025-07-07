# paths
vpath %.c srcs/utils
vpath %.c srcs/events

BUILD_DR = ./build/
NAME = cub3d

LIBFT_DR = ./libft
LIBFT = -L$(LIBFT_DR) -lft
INCLUDES_DRS = -I./includes -I./libft/includes 
HEADERS = ./includes/utils.h ./includes/container.h ./includes/events.h ./includes/settings.h ./includes/types.h
FLAGS = -Wall -Wextra -Werror #-fsanitize=address #-g3 #

INCLUDES_DRS = -I./includes -I./libft/includes
CC = cc
RM = rm -f

# srcs
F_UTILS = rewirte_mlx.c free_methods.c handel_exit.c
F_EVENTS = destroy.c loop.c  key_hook.c

SRCS= main.c $(F_UTILS) $(F_EVENTS)
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
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm  -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
