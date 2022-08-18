/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:13:40 by junekim           #+#    #+#             */
/*   Updated: 2022/08/15 11:06:47 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEY_PRESS 2
# define EXIT 17

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# define NO_MAP 0
# define NO_WALL 1
# define NO_EXIT 2
# define NO_COLLECTIBLE 3
# define NO_START_POSITION 4
# define NO_RECTANGULAR 5

typedef struct s_images {
	int		width;
	int		height;
	void	*grass;
	void	*fence;
	void	*cow0;
	void	*cf0;
	void	*chest0;
}	t_images;

typedef struct s_map_info {
	size_t	width;
	size_t	height;
	int		exit;
	int		collectible;
	int		start_position;
	char	*map_string;
}	t_map_info;

typedef struct s_game_manager {
	void		*mlx;
	void		*win;
	int			clear;
	int			move_num;
	t_map_info	*map_info;
	t_images	*images;
}	t_game_manager;

char	*get_next_line(int fd);

void	file_error(void);
void	open_error(void);
void	error_manager(t_game_manager *gm);
void	map_error(int flag, t_game_manager *gm);

void	finish(t_game_manager *gm);
int		close_game(t_game_manager *gm);

void	map_parser(t_game_manager *gm, char *file_name);
void	map_update(t_game_manager *gm);
void	init(t_game_manager *gm, t_map_info *mi, t_images *im, char *fn);
void	image_48(t_game_manager *gm, void *image, int width, int height);
int		move(int dir, t_game_manager *gm);
#endif