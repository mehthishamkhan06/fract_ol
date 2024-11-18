/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:08:53 by mohkhan           #+#    #+#             */
/*   Updated: 2024/11/18 16:08:59 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	ft_putstr_fd("Error: malloc failed\n", 2);
	exit(1);
}

void	digit_error(void)
{
	ft_putstr_fd("Error: Please enter a valid digit\n", 2);
	exit(1);
}

void	over_flow_error(void)
{
	ft_putstr_fd("Error Please Look What You Have Given as an Argument\n", 2);
	exit(1);
}

void	ft_error(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot/julia] [re] [im]\n", 2);
	exit (1);
}

int	destroy_fractal(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	exit(0);
}
