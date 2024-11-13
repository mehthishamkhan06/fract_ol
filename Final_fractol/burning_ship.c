#include "fractol.h"

static	double  scale(double num, double new_min, double new_max)
{
	return ((new_max - new_min) * (num - 0) / (WIDTH - 0)
		+ new_min);
}

static  void	handle_pixel_burn(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.re = (scale(x, -2, 2) * fractal->view) + fractal->x_offset;
	z.im = (scale(y, 2, -2) * fractal->view) + fractal->y_offset;
	c.re = z.re;
	c.im = z.im;
	i = 0;
	while (i < fractal->no_of_iterations)
	{
		z.re = fabs(z.re);
		z.im = (-1) * fabs(z.im);
		z = complex_add(complex_square(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
            color = map(i, BLUE, BLACK, 0, fractal->no_of_iterations);
			my_mlx_pixel_put( x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(x, y, &fractal->img, WHITE);
}

void    burningship(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while(++x < WIDTH)
            handle_pixel_burn(x, y, fractal);
    }
    mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);  
}