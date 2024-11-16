#include "fractol.h"

static	void	initialize_fractal2(t_fractal *fractal)
{
	fractal -> mlx = mlx_init();
	if (!fractal -> mlx)
		malloc_error();
	fractal -> win = mlx_new_window(fractal -> mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractal -> win)
	{
		free (fractal -> mlx);
		malloc_error();
	}
	fractal -> img.img_ptr = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
	if (!fractal -> img.img_ptr)
	{
		mlx_destroy_window(fractal -> mlx, fractal -> win);
		free(fractal -> mlx);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal -> img.img_ptr,
			&fractal->img.bpp, &fractal->img.ln_len, &fractal->img.endian);
	if (!fractal -> img.pixels_ptr)
	{
		mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
		mlx_destroy_window(fractal -> mlx, fractal -> win);
		free(fractal -> mlx);
		malloc_error();
	}
}

static	void	initialize_fractal(t_fractal *fractal)
{
	fractal -> view = 1;
	fractal -> no_of_iterations = 100;
	fractal -> x_offset = 0.0;
	fractal -> y_offset = 0.0;
	fractal -> escape_value = 4;
	initialize_fractal2(fractal);
}

static	void	init_julia(t_fractal *fractal, char *argv[])
{
	if (!ft_isdigit_str(argv[2]) && !ft_isdigit_str(argv[3]))
	{
		fractal -> x = ft_atodbl(argv[2]);
		fractal -> y = ft_atodbl(argv[3]);
		return ;
	}
	else
		digit_error();
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
		init_julia(fractal, argv);
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
		ft_error();
}
