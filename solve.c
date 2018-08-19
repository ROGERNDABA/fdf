/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:47:18 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 15:47:20 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int arr_struct(t_solve)

/*void drawline(t_fdf *e, int x0, int y0, int x1, int y1)
{
	int dx, dy, p;

	dx=x1-x0;
	dy=y1-y0;
	p=2*dy-dx;

	while(x0<x1)
	{
		if(p>=0)
		{
			mlx_pixel_put(e->ptr, e->win, x0, y0, 255);
			y0=y0+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			mlx_pixel_put(e->ptr, e->win, x0, y0, 255);
			p=p+2*dy;
		}
		x0=x0+1;
	}
}

void	draw_line(t_fdf *e, t_solve *funct)
{
	int dx;
	int dy;
	int p;

	dx = funct->x1 - funct->x;
	dy = funct->y1 - funct->y;


}*/

void 	funct(t_stuff *stuff, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < stuff->lin_len)
	{
		j = 0;
		while (j < stuff->c_count - 1)
		{
			mlx_pixel_put(fdf->ptr, fdf->win, 200 + (j * 20 + stuff->tab[i][j]*20),\
				200 + (i * 20 + stuff->tab[i][j + 1] *20), 0xF00000);
			j++;
		}
		i++;
	}
}
