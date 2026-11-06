/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:25:12 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:10:40 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1440
# define HEIGHT 810
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define BLOCK_SIZE 24
# define WALLCOLOR_MINIMAP 0xa5f970
# define CELLINGCOLOR 0x4b736b
# define WALL_COLOR 0x00feea
# define PLAYER_COLOR 0xfe0054
# define SIZE_PLAYER 2
# define PI 3.14159265358979
# define FOV 1.1519173063

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				is_malloc;
	struct s_image	*mips;
}	t_image;

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

typedef struct s_bilin
{
	unsigned int	c00;
	unsigned int	c10;
	unsigned int	c01;
	unsigned int	c11;
	float			fu;
	float			fv;
}	t_bilin;

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
}	t_raycast;

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

typedef struct s_move
{
	int	dx;
	int	dy;
}	t_move;

typedef struct s_player
{
	float		angle;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	t_position	pos;
	t_position	old_pos;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			look_left;
	int			look_right;
}	t_player;

typedef struct s_data
{
	t_player	player;
	t_image		image;
	t_texture	texture;
	t_image		tex_no;
	t_image		tex_so;
	t_image		tex_we;
	t_image		tex_ea;
	t_color		floor;
	t_color		ceiling;
	t_mlx		data;
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
void	move_player(t_data *data, float cos_angle, float sin_angle, int speed);
void	init_player(t_data *data);
void	render(t_data *data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	update_camera_vectors(t_player *player);
void	raycast(t_data *data, t_image *img);
void	insert_texture(t_image *img, t_raycast ray, int x, float wall_x);
t_image	*select_mip(t_image *tex, float step);
void	check_help(t_data *t_map);
void	check_is_around_wall(t_data *data);
void	count_line_map(t_data *map, char *av);
void	check_extension_map(t_data *data, char *av);
char	*get_next_line(int fd);
int		is_map_line(char *line);
int		rgb_to_int(t_color color);
void	load_textures(t_data *data);
void	build_mipmaps(t_image *img);
t_image	down_scale(t_image base, int nw, int nh);
void	free_mipmaps(t_image *img);
void	calc_perp_wall_dist(t_data *data, t_raycast *ray);
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
int		is_valid_color(char **mat);
char	*remove_reverse_space(char *line);

#endif
