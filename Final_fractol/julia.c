#include "fractol.h"

static	void	handle_pixel_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.re = (map(x, -2, +2, WIDTH) * fractal->view) + fractal->x_offset;
	z.im = (map(y, -2, +2, HEIGHT) * fractal->view) + fractal->y_offset;
	c.re = fractal->x;
	c.im = fractal->y;
	while (i < fractal->no_of_iterations)
	{
		z = complex_add(complex_square(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->no_of_iterations);
			my_mlx_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_mlx_pixel_put(x, y, &fractal->img, BLUE);
}

void	julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel_julia(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img_ptr, 0, 0);
}
