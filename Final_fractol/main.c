/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:09:48 by mohkhan           #+#    #+#             */
/*   Updated: 2024/11/18 16:09:50 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char*argv[])
{
	t_fractal	fractal;

	if (argc > 1 && argc < 5)
	{
		check_and_init_fractol(argc, argv, &fractal);
		mlx_key_hook(fractal.win, key_movements, &fractal);
		mlx_mouse_hook(fractal.win, mouse_movements, &fractal);
		mlx_hook(fractal.win, 17, 6, destroy_fractal, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
		ft_error();
	return (0);
}
