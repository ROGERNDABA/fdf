#include <mlx.h>
#include <stdlib.h>

typedef struct  s_fdf
{
	void        *ptr;
	void        *win;
}                t_fdf;

int key_hook(int keycode)
{
    if (keycode == 53)
        exit(EXIT_SUCCESS);
    return (0);
}



void drawline(t_fdf *e, int x0, int y0, int x1, int y1)
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

int main()
{
    t_fdf* e;
    e = (t_fdf *)malloc(sizeof(t_fdf));
    e->ptr = mlx_init();
    e->win = mlx_new_window(e->ptr, 800, 800, "42");
    drawline(e, 0, 0, 100, 100);
    mlx_key_hook(e->win, key_hook, e->ptr);
    mlx_loop(e->ptr);
    return 0;
}
