/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:22:31 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 15:27:33 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_IO_H
# define FILE_IO_H
# include "map.h"

t_map	*open_argv(int argc, char **argv); // argc==0일때
void	open_file(char **argv, int i, t_map *map_arr);
char	*malloc_line(int size);
int		strlen(char *str);
int		find_file_size(int fd);
char	*strcpy(char *dest, char *src);
char	*read_file(int fd, int i, int file_size);
int		read_info(char *str, t_map *map_arr, int i);
void	read_map(char *str, t_map *map_arr, int i);
char	*copy_map(char *str, t_map *map_arr, int i, int row);
int		line_len(char *str);
#endif