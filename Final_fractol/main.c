#include "fractol.h"

int	main(int argc, char*argv[])
{
	t_fractal	fractal;

	if (argc > 1 && argc < 5)
	{
		check_and_init_fractol(argc, argv, &fractal);		
		mlx_key_hook(fractal.win, key_movements, &fractal);
		mlx_mouse_hook(fractal.win, mouse_movements, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol [mandelbrot/julia] [re] [im]\n", 2);
		return (1);
	}
	return (0);
}
