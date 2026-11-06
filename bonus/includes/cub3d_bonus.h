/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:25:12 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/22 16:12:46 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define WIDTH 1440
# define HEIGHT 810
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define BLOCK_SIZE 24
# define WALL_COLOR 0x00feea
# define SIZE_PLAYER 2
# define PI 3.14159265358979
# define FOV 1.1519173063
# define SPACE 32
# define ENTER 65293
# define TEX_SIZE 1024
# define DOOR_FRAMES 11
# define DOOR_SPEED 2
# define DOOR_REACH 48.0f
# define DOOR_PATH "./textures/door/"
# define TX_TRANSPARENT 0xff000000
# define CELLINGCOLOR 0x4b736b
# define SPRITE_COUNT 10
# define SPRITE_NB 5
# define SPRITE_PATH "./textures/sprites/"
# define SPRITE_ANIM_SPEED 8
# define SPRITE_SPEED 0.3f
# define SPRITE_COLLISION 20.0f
# define SPRITE_MIN_SPAWN_DIST 4.0f
# define GAME_OVER_PATH "./textures/game_over/game_over.xpm"
# define COVER_PATH "./textures/cover/cover.xpm"
# define COVER_NB 4
# define COVER_DELAY_SEC 5
# define COVER_ANIM_SPEED 30
# define MINIMAP_HEIGHT 195
# define MINIMAP_WIDTH 195
# define MOUSE_SENSITIVITY 0.0015
# define MINIMAP_OFFSET_X 13
# define MINIMAP_OFFSET_Y 13
# define MINIMAP_TILE_SIZE 13
# define MINIMAP_PLAYER_SIZE 10
# define PLAYER_MARGIN 10
# define MINIMAP_SPRITE_COLOR 0xFF0000
# define MINIMAP_DOOR_CLOSED_COLOR 0x8B4513
# define MINIMAP_DOOR_OPEN_COLOR 0xFF8C00

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	float			aspect;
	int				is_malloc;
	struct s_image	*mips;
}	t_image;

typedef struct s_raycast
{
	float	camera_x;
	float	pos_x;
	float	pos_y;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	float	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_image	*tex;
	int		hit_door;
	int		door_open;
	float	door_perp_dist;
	int		door_side;
	int		door_map_x;
	int		door_map_y;
}	t_raycast;

typedef struct s_door
{
	int				map_x;
	int				map_y;
	float			progress;
	int				moving;
	struct s_door	*next;
}	t_door;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	*line;
	char	*str;
	char	*tmp;
	int		count_player;
	int		fd;
	int		x;
	int		y;
}	t_mlx;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_player
{
	float		angle;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		turn_speed;
	t_position	pos;
	t_position	old_pos;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			look_left;
	int			look_right;
	int			door_key;
}	t_player;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	dist;
	int		current_frame;
	int		anim_timer;
}	t_sprite;

typedef struct s_bilin
{
	unsigned int	c00;
	unsigned int	c10;
	unsigned int	c01;
	unsigned int	c11;
	float			fu;
	float			fv;
}	t_bilin;

typedef struct s_sampler
{
	t_image			*tex;
	int				x;
	int				draw_start;
	int				draw_end;
	int				ifu;
	int				bpp;
	float			fu;
	float			step;
	float			tex_pos;
}	t_sampler;

typedef struct s_proj
{
	float	t0;
	float	t1;
	int		screen;
	int		size_h;
	int		size_w;
	int		raw;
}	t_proj;

typedef struct s_mini
{
	int			px;
	int			py;
	int			new_x;
	int			new_y;
	int			size;
	int			mouse_moved;
	int			player_img_width;
	int			player_img_height;
	float		cos_a;
	float		sin_a;
	void		*player_img;
}	t_mini;

typedef struct s_data
{
	t_player	player;
	t_image		image;
	t_texture	texture;
	t_image		tex_no;
	t_image		tex_so;
	t_image		tex_we;
	t_image		tex_ea;
	t_image		tex_door[11];
	t_door		*doors;
	t_image		sprite_frames[SPRITE_COUNT];
	t_sprite	*sprites;
	int			sprite_count;
	float		z_buffer[WIDTH];
	int			game_over;
	int			game_over_loaded;
	int			game_over_drawn;
	t_image		game_over_tex;

	int			start_screen;
	int			cover_loaded;
	int			cover_index;
	int			cover_timer;
	time_t		cover_start;
	t_image		cover_tex[COVER_NB];
	t_color		floor;
	t_color		ceiling;
	t_mlx		data;
	t_mini		mini;
	int			count_line;
	int			index_map;
	int			check;
	char		*line_check_floor;
	char		*line_check_ceilling;
	char		**map;
}	t_data;

void	cleanup(t_data *data);
void	ft_free_map(char **map);
void	map(char *av, t_data *map);
void	ft_map_size(t_data *data);
void	set_map(t_data *map, char *line);
int		close_x(t_data *data);
int		keyboard_event(int keyboard, t_data *data);
int		key_release(int keyboard, t_data *data);
int		game_loop(t_data *data);
void	move_player(t_data *data, float dir_x, float dir_y, int speed);
void	init_player(t_data *data);
void	render(t_data *data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	update_camera_vectors(t_player *player);
void	raycast(t_data *data, t_image *img);
void	check_help(t_data *t_map);
void	check_is_around_wall(t_data *data);
char	get_cell(t_data *map, int x, int y);
void	check_door(t_data *map);
void	count_line_map(t_data *map, char *av);
void	check_extension_map(t_data *data, char *av);
char	*get_next_line(int fd);
int		is_map_line(char *line);
int		rgb_to_int(t_color color);
void	load_textures(t_data *data);
void	resize_to_tex(t_data *data, t_image *tex);
void	build_mipmaps(t_image *img);
t_image	down_scale(t_image base, int nw, int nh);
void	free_mipmaps(t_image *img);
void	calc_perp_wall_dist(t_data *data, t_raycast *ray);
void	insert_texture(t_image *img, t_raycast ray, int x, float wall_x);
void	insert_door(t_data *data, t_image *img, t_raycast *ray, int x);
void	overlay_pixel(t_image *img, int x, int y, unsigned int color);
float	door_wall_x(t_raycast *ray);
int		door_frame_index(t_data *data, t_raycast *ray);
void	clean_file(int fd);
void	save_ceiling(t_data *map, char *line);
void	save_floor(t_data *map, char *line);
void	save_map_line(t_data *map, char *line);
void	save_no(t_data *map, char *line);
void	save_so(t_data *map, char *line);
void	save_we(t_data *map, char *line);
void	save_ea(t_data *map, char *line);
int		check_space_and_break(char *line);
int		is_valid_texture(char *line);
int		is_hidden_file(char *path);
int		is_valid_color(char **mat);
char	*remove_reverse_space(char *line);
void	load_door_textures(t_data *data);
void	init_doors(t_data *data);
void	free_doors(t_data *data);
void	toggle_door(t_data *data);
int		update_doors(t_data *data);
t_door	*find_door(t_data *data, int map_x, int map_y);
int		is_door_closed(t_data *data, int map_x, int map_y);
int		cell_blocked(t_data *data, int map_x, int map_y);
void	load_sprite_frames(t_data *data);
void	init_sprites(t_data *data);
void	free_sprites(t_data *data);
void	animate_sprites(t_data *data);
void	render_sprites(t_data *data, t_image *img);
void	draw_sprite(t_data *data, t_image *img, t_sprite *sprite, t_proj *p);
int		move_sprites(t_data *data);
void	sort_sprites(t_data *data);
int		random_cell_y(t_data *data, int cx);
int		is_valid_spawn(t_data *data, int cell_x, int cell_y);
void	show_game_over(t_data *data);
void	load_game_over_image(t_data *data);
void	load_cover_images(t_data *data);
void	show_cover(t_data *data);
void	cover_image_delete(t_data *data);
void	check_map_letter(t_data *map);
int		move_mouse(int x, int y, t_data *data);
int		inside_minimap_circle(int x, int y);
int		get_player_pixel(t_data *data, t_image *img, int dx, int dy);
char	*remove_reverse_space(char *line);
void	draw_minimap(t_data *data, t_image *image);
void	draw_rotated_player(t_data *data, t_image *image, t_image *img);
void	draw_minimap_map_aux(t_data *data, t_image *image,
			float player_x, float player_y);
void	draw_square(t_image *image, int x, int y, int color);
void	draw_circle(t_data *data, t_image *image, int x, int y);
int		minimap_cell_color(char cell);
int		minimap_pixel_is_wall(t_data *data, int ox, int oy);
void	init_player_minimap(t_data *data);
#endif
