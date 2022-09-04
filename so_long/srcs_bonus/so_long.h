/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:13:40 by junekim           #+#    #+#             */
/*   Updated: 2022/08/19 18:37:50 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEY_PRESS 2
# define EXIT 17

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define SPACE 49

# define NO_MAP 0
# define NO_WALL 1
# define NO_EXIT 2
# define NO_COLLECTIBLE 3
# define NO_START_POSITION 4
# define NO_RECTANGULAR 5

# define SPEED 100

typedef struct s_position
{
	int		exist;
	int		dir;
	int		type;
	int		time;
	char	*ptr;
	size_t	width;
	size_t	height;
}	t_position;

typedef struct s_animation
{
	int			exit;
	int			enemy_num;
	t_position	*flag;
	t_position	*enemy;
	t_position	*missile_fighter;
	t_position	*missile_enemy;
}	t_animation;

typedef struct s_images
{
	int		width;
	int		height;
	void	*chest;
	void	*enemy_body;
	void	*grass;
	void	*house;
	void	*topgun;
	void	*black_64;
	void	*black_96;
	void	*enemy_64[2];
	void	*missile_fighter[4];
	void	*missile_enemy[4];
	void	*chest_64[3];
	void	*flag[3];
	void	*explosion[3];
	void	*explosion_64[3];
	void	*fighter_96[3];
	void	*alphabet_64[4];
	void	*alphabet[8];
	void	*number[10];
	void	*enemy[12];
	void	*fighter[12];
}	t_images;

typedef struct s_map_info {
	size_t	width;
	size_t	height;
	int		exit;
	int		collectible;
	int		start_position;
	int		enemy;
	char	*map_string;
}	t_map_info;

typedef struct s_game_manager {
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			dir;
	int			clear;
	int			move_num;
	int			topgun;
	int			time;
	int			time_64;
	int			screen_width;
	int			screen_height;
	int			chest_open;
	int			enemy_destroy;
	int			finish;
	t_map_info	*map_info;
	t_images	*images;
	t_animation	*animation;
}	t_game_manager;

char	*get_next_line(int fd);
void	file_error(void);
void	open_error(void);
void	error_manager(t_game_manager *gm);
void	map_error(int flag, int fd ,t_game_manager *gm);
void	finish(t_game_manager *gm);
void	init_images(t_game_manager *gm, t_images *images);
void	map_parser(t_game_manager *gm, char *file_name);
void	map_update(t_game_manager *gm);
void	init(t_game_manager *gm, t_map_info *mi, t_images *im, char *fn);
int		move(int dir, t_game_manager *gm);
int		move_start(int dir, t_game_manager *gm);
int		close_game(t_game_manager *gm);
int		frame_update(t_game_manager *gm);
void	init_images_sub5(t_game_manager *gm, t_images *im);
void	image_32(t_game_manager *gm, void *image, int width, int height);
void	animate_image_32(t_game_manager *gm, void **image, int w, int h);
void	animate_image_32_2(t_game_manager *gm, void **image, int w, int h);
void	start_page(t_game_manager *gm);
void	image_96(t_game_manager *gm, void *image, int width);
void	animate_image_96(t_game_manager *gm, void **image, int w);
void	missile(t_game_manager *gm);
void	missile_move(t_game_manager *gm, t_position *position);
void	animate_image_64(t_game_manager *gm, void **image);
void	mi(t_game_manager *gm, void *image, int width, int height);
void	print_move(t_game_manager *gm);
void	init_animation(t_game_manager *gm);

#endif