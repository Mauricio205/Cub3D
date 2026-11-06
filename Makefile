NAME = cub3D
NAME_BONUS = cub3D_bonus 

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -Iminilibx-linux -Ilib/libft

CC = @cc

MLX = minilibx-linux/libmlx_Linux.a

LIBFT = lib/libft/libft.a 

UTILS = src/utils

FREE = src/free

HOOKS = src/hooks

LIB = lib/get_next_line

PARS = src/parsing

RAY = src/raycast

RENDER = src/render

INCLUDES = includes

BONUS = bonus

SRC_BONUS = $(BONUS)/src/main_bonus.c $(BONUS)/$(FREE)/ft_cleaned_bonus.c \
	$(BONUS)/$(FREE)/free_bonus.c $(LIB)/get_next_line.c \
	$(BONUS)/$(PARS)/set_map_bonus.c $(BONUS)/$(PARS)/map_bonus.c \
	$(BONUS)/$(UTILS)/check_map_bonus.c $(BONUS)/$(HOOKS)/events_bonus.c \
	$(LIB)/get_next_line_utils.c $(BONUS)/$(UTILS)/utils_bonus.c \
	$(BONUS)/$(UTILS)/check_door_bonus.c \
	$(BONUS)/$(RAY)/game_loop_bonus.c $(BONUS)/$(RAY)/raycasting_bonus.c \
	$(BONUS)/$(RENDER)/render_bonus.c $(BONUS)/$(RAY)/raycasting_utils_bonus.c \
	$(BONUS)/$(RAY)/draw_texture_bonus.c $(BONUS)/$(RAY)/door_draw_bonus.c \
	$(BONUS)/$(RAY)/door_geom_bonus.c $(BONUS)/$(RAY)/move_player_bonus.c \
	$(BONUS)/$(RAY)/perp_wall_dist_bonus.c $(BONUS)/$(UTILS)/set_map_aux0_bonus.c \
	$(BONUS)/$(UTILS)/set_map_aux1_bonus.c $(BONUS)/$(UTILS)/utils_01_bonus.c \
	$(BONUS)/$(UTILS)/file_name_bonus.c $(BONUS)/$(HOOKS)/mouse_bonus.c \
	$(BONUS)/$(RAY)/door_bonus.c $(BONUS)/$(RAY)/door_state_bonus.c \
	$(BONUS)/$(RAY)/door_toggle_bonus.c $(BONUS)/$(UTILS)/mipmap_bonus.c \
	$(BONUS)/$(UTILS)/mipmap_build_bonus.c $(BONUS)/$(RAY)/sprite_bonus.c \
	$(BONUS)/$(RAY)/sprite_render_bonus.c $(BONUS)/$(RAY)/sprite_draw_bonus.c \
	$(BONUS)/$(RAY)/sprite_scan_bonus.c $(BONUS)/$(RAY)/sprite_random_bonus.c \
	$(BONUS)/$(RAY)/sprite_life_bonus.c $(BONUS)/$(RAY)/sprite_anim_bonus.c \
	$(BONUS)/$(RAY)/sprite_sort_bonus.c $(BONUS)/$(RENDER)/game_over_bonus.c \
	$(BONUS)/$(RENDER)/cover_bonus.c $(BONUS)/$(RENDER)/cover_load_bonus.c \
	$(BONUS)/$(RENDER)/pixel_utils_bonus.c \
	$(BONUS)/$(RENDER)/sampler_bonus.c $(BONUS)/src/check_extension_bonus.c \
	$(BONUS)/src/check_map_letter_bonus.c $(BONUS)/$(UTILS)/minimap_utils_bonus.c \
	$(BONUS)/$(UTILS)/minimap_utils1_bonus.c $(BONUS)/$(UTILS)/mini_map_bonus.c

SRC = src/main.c $(FREE)/ft_cleaned.c \
	$(FREE)/free.c $(LIB)/get_next_line.c \
	$(PARS)/set_map.c $(PARS)/map.c \
	$(UTILS)/check_map.c $(HOOKS)/events.c \
	$(LIB)/get_next_line_utils.c $(UTILS)/utils.c \
	$(RAY)/game_loop.c $(RAY)/raycasting.c \
	$(RAY)/move.c $(RENDER)/render.c $(RAY)/raycasting_utils.c \
	$(RAY)/draw_texture.c \
	$(RAY)/perp_wall_dist.c $(UTILS)/set_map_aux0.c \
	$(UTILS)/set_map_aux1.c $(UTILS)/utils_01.c $(UTILS)/mipmap.c \
	$(UTILS)/mipmap_build.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

MAKE = @make
ECHO = @echo

RM = @rm -rf

HEADER = includes/cub3d.h

ifeq ($(BONUS_FLAG), 1)
	NAME = $(NAME_BONUS)
	HEADER = bonus/includes/cub3d_bonus.h
	OBJS = $(OBJS_BONUS)
	INCLUDES = bonus/includes
	CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -Iminilibx-linux -Ilib/libft
endif

all: $(NAME)

$(LIBFT):
	$(MAKE) -s -C lib/libft

$(MLX):
	$(MAKE) -s -C minilibx-linux > /dev/null 2>&1 

$(OBJS): $(HEADER)

$(NAME): $(HEADER) $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm -o $(NAME)
	$(ECHO) '  ______             __         ______         __' 
	$(ECHO) ' /      \           |  \       /      \       |  \'
	$(ECHO) '|  $$$$$$$$$$$$\ __    __ | $$$$____  |  $$$$$$$$$$$$\  ____| $$$$'
	$(ECHO) '| $$$$   \$$$$|  \  |  \| $$$$    \  \$$$$__| $$$$ /      $$$$'
	$(ECHO) '| $$$$      | $$$$  | $$$$| $$$$$$$$$$$$$$\  |     $$$$|  $$$$$$$$$$$$$$'
	$(ECHO) '| $$$$   __ | $$$$  | $$$$| $$$$  | $$$$ __\$$$$$$$$$$\| $$$$  | $$$$'
	$(ECHO) '| $$$$__/  \| $$$$__/ $$$$| $$$$__/ $$$$|  \__| $$$$| $$$$__| $$$$'
	$(ECHO) '\ $$$$    $$$$ \$$$$    $$$$| $$$$    $$$$ \$$$$    $$$$ \$$$$    $$$$'
	$(ECHO) ' \$$$$$$$$$$$$    \$$$$$$$$$$$$  \$$$$$$$$$$$$$$   \$$$$$$$$$$$$   \$$$$$$$$$$$$$$ '
	@echo "\e[1;32mCompilado com sucesso!\e[0m"

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(MAKE) -s -C minilibx-linux clean > /dev/null 2>&1 
	$(MAKE) -s -C lib/libft clean
	$(ECHO) "\e[1;32mclean >> limpado\e[0m"

bonus:
	$(MAKE) BONUS_FLAG=1 all

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -s -C lib/libft fclean
	$(ECHO) "\e[1;32mfclean >> limpado\e[0m"

re: fclean all

.PHONY: all clean fclean re bonus
