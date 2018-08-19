/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:40:46 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 08:40:48 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include "libft/incl/libft.h"

typedef struct		s_stuff
{
	int				c_count;
	int				lin_len;
	int				**tab;
}					t_stuff;

typedef struct		s_solve
{
	int				x;
	int				y;
	int				x1;
	int				y1;
}					t_solve;

typedef struct		s_fdf
{
	void			*ptr;
	void			*win;
}					t_fdf;

t_stuff				*tab_map(int fd, char *file);
int					key_hook(int keycode);
void 				funct(t_stuff *stuff, t_fdf *fdf);

#endif
