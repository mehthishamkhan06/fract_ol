#include "fractol.h"

static	void	initialize_fractal2(t_fractal *fractal)
{
	fractal -> mlx = mlx_init();
	fractal -> win = mlx_new_window(fractal -> mlx, WIDTH, HEIGHT, "Fractol");
	// if (!fractal -> win)
	// {
	//     mlx_destroy_display(fractal -> mlx);
	//     free(fractal -> mlx);
	//     malloc_error();
	// }
	fractal -> img.img_ptr = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
	if (!fractal -> img.img_ptr)
	{
		mlx_destroy_window(fractal -> mlx, fractal -> win);
		// mlx_destroy_display(fractal -> mlx);
		free(fractal -> mlx);
		malloc_error();
	}
	fractal -> img.pixels_ptr = mlx_get_data_addr(fractal -> img.img_ptr,
			&fractal -> img.bpp, &fractal -> img.line_len,
			&fractal -> img.endian);
	if (!fractal -> img.pixels_ptr)
	{
		mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
		mlx_destroy_window(fractal -> mlx, fractal -> win);
		// mlx_destroy_display(fractal -> mlx);
		free(fractal -> mlx);
		malloc_error();
	}
}

static	void	initialize_fractal(t_fractal *fractal)
{
	fractal -> view = 1;
	fractal -> no_of_iterations = 70;
	fractal -> x_offset = 0.0;
	fractal -> y_offset = 0.0;
	fractal -> escape_value = 4;
	initialize_fractal2(fractal);
}

void	check_and_init_fractol(int ac, char *argv[], t_fractal *fractal)
{
	if (ac == 2 && (strcmp(argv[1], "mandelbrot") == 0))
	{
		fractal -> fractal_type = 1;
		initialize_fractal(fractal);
		mandelbrot(fractal);
	}
	else if (ac == 4 && (strcmp(argv[1], "julia") == 0))
	{
		fractal -> fractal_type = 2;
		fractal -> x = ft_atodbl(argv[2]);
		fractal -> y = ft_atodbl(argv[3]);
		initialize_fractal(fractal);
		julia(fractal);
	}
	else if (ac == 2 && (strcmp(argv[1], "burningship") == 0))
	{
		fractal -> fractal_type = 3;
		initialize_fractal(fractal);
		burningship(fractal);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol [mandelbrot/julia] [re] [im]\n", 2);
		exit (1);
	}
}
