#include "fractol.h"

static	void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
    z.re = 0.0;
    z.im = 0.0;
	c.re = (map(x, -2, +2, 0, WIDTH)* fractal->view) + fractal->x_offset;
	c.im = (map(y, +2, -2, 0, HEIGHT)* fractal->view) + fractal->y_offset;
	while (i < fractal->no_of_iterations)
	{
		z = complex_add(complex_square(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->no_of_iterations);
			my_mlx_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;	
	}
	my_mlx_pixel_put(x, y, &fractal->img, WHITE);
}
void    mandelbrot(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while(++x < WIDTH)
            handle_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);  
}