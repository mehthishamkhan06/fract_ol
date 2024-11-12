#include "fractol.h"
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
    z.x = 0.0;
    z.y = 0.0;
	c.x = (map(x, -2, +2, 0, WIDTH);
	c.y = (map(y, +2, -2, 0, HEIGHT);


	while (i < fractal->no_of_iterations)
	{
		// actual z^2 + c	
		// z = z^2 + c
		z = sum_complex(square_complex(z), c);
		
		// Is the value escaped???
		// if hypotenuse > 2 i assume the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->no_of_iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;	
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
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
    mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img, 0, 0);  
}