/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:42:31 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 08:42:32 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
    int		fd;
	t_fdf*	e;
    t_stuff *arr;

	//char	*line = NULL;
	if (ac == 1)
		fd = 0;
	else if (ac == 2)
    {
		fd = open(av[1], O_RDONLY);
    }
	else
		return (2);
     arr = tab_map(fd, av[1]);
	 e = (t_fdf *)malloc(sizeof(t_fdf));
	 e->ptr = mlx_init();
	 e->win = mlx_new_window(e->ptr, 800, 800, "42");
	 funct(arr, e);
	 //mlx_key_hook(e->win, key_hook, e->ptr);
	 mlx_loop(e->ptr);
	if (ac == 2)
		close(fd);
}
