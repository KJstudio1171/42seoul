/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_io.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:12:59 by junekim           #+#    #+#             */
/*   Updated: 2021/09/28 20:20:35 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_IO_H
# define FT_FILE_IO_H
# include "ft_map.h"
t_map	*ft_open_argv(int argc, char **argv); // argc==0일때
void	ft_open_file(char **argv, int i, t_map *map_arr);
char	*ft_malloc_line(int size);
int		ft_strlen(char *str);
int		ft_find_file_size(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_read_file(int fd, int i, int file_size);
int		ft_read_info(char *str, t_map *map_arr, int i);
void	ft_read_map(char *str, t_map *map_arr, int i);
char	*ft_copy_map(char *str, t_map *map_arr, int i, int row);
int		ft_line_len(char *str);
#endif