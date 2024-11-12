#include "fractol.h"

static void my_mlx_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
    z.re = 0.0;
    z.im = 0.0;
	
	c.re = (map(x, -2, +2, 0, WIDTH));
	c.im = (map(y, +2, -2, 0, HEIGHT));
	// c.re = z.re;
	// c.im = z.im;


	while (i < fractal->no_of_iterations)
	{
		z = complex_add(complex_square(z), c);
		
		// printf("z.re: %f\n", z.re);
		// printf("z.im: %f\n", z.im);
		// exit(1);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->no_of_iterations);
			// printf("x: %d\n", x);
			// printf("y: %d\n", y);
			// printf("color: %d\n", color);
			// printf("i: %d\n", i);
			// printf("no_of_iterations: %d\n", fractal->no_of_iterations);
			// printf("%p\n", &fractal->img);
			my_mlx_pixel_put(x, y, &fractal->img, color);
			// printf("hello\n");
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