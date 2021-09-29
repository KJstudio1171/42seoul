/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:22:31 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 16:56:36 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_IO_H
# define FILE_IO_H
# include "map.h"

t_map	*open_argv(int argc, char **argv); // argc==0일때
void	open_file(char **argv, int i, t_map *map_arr);
char	*malloc_line(int size);
int		find_file_size(int fd);
char	*read_file(int fd, int file_size);
int		read_info(char *str, t_map *map_arr, int i);
void	read_map(char *str, t_map *map_arr, int i);
char	*copy_map(char *str, t_map *map_arr, int i, int row);
int		line_len(char *str);
void	open_stdin_file(char **argv, t_map *map_arr);
char	*read_stdin_file(void);
void	print_map(t_map *map_arr, int i);//삭제요망
#endif