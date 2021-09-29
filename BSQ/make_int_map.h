#include "ft_map.h"

void	plus_one(int x, int y,t_map *box);
void	make_int_map(t_map *box);
int		check_possible(int x, int y, int size, char **int_map);
void 	search_biggest(t_map *box);
void	draw_in_map(int	*map, t_map *box);