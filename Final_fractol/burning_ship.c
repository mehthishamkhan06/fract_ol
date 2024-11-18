/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:08:42 by mohkhan           #+#    #+#             */
/*   Updated: 2024/11/18 16:08:44 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	handle_pixel_burn(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.re = (map(x, -2, 2, WIDTH) * fractal->view) + fractal->x_offset;
	z.im = (map(y, 2, -2, HEIGHT) * fractal->view) + fractal->y_offset;
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
			color = map(i, BLACK, WHITE, fractal->no_of_iterations);
			my_mlx_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	burningship(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel_burn(x, y, fractal);
	}
	mlx_put_image_to_window(fractal -> mlx, fractal -> win,
		fractal -> img.img_ptr, 0, 0);
}
