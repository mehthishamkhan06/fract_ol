/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:09:06 by mohkhan           #+#    #+#             */
/*   Updated: 2024/11/18 16:09:08 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bonus_view(t_fractal *fractal, int mouse_x, int mouse_y, int flag)
{
	double	x;
	double	y;
	double	display_x;
	double	display_y;

	x = 0;
	y = 0;
	display_x = 0;
	display_y = 0;
	x = (map(mouse_x, -2, 2, HEIGHT) * fractal->view) + fractal->x_offset;
	y = (map(mouse_y, 2, -2, WIDTH) * fractal->view) + fractal->y_offset;
	if (flag == 1)
		fractal->view /= 1.25;
	else if (flag == -1)
		fractal->view *= 1.25;
	display_x = (map(mouse_x, -2, 2, HEIGHT) * fractal->view)
		+ fractal->x_offset;
	display_y = (map(mouse_y, 2, -2, WIDTH) * fractal->view)
		+ fractal->y_offset;
	fractal->x_offset += (x - display_x);
	fractal->y_offset += (y - display_y);
}

int	mouse_movements(int mouse_code, int x, int y, t_fractal *fractal)
{
	mlx_clear_window(fractal -> mlx, fractal -> win);
	mlx_mouse_get_pos(fractal -> win, &x, &y);
	if (mouse_code == 1)
		bonus_view(fractal, x, y, 1);
	if (mouse_code == 2)
		bonus_view(fractal, x, y, -1);
	if (mouse_code == 5)
		fractal -> view *= 1.1;
	if (mouse_code == 4)
		fractal -> view /= 1.1;
	if (fractal -> fractal_type == 1)
		mandelbrot(fractal);
	else if (fractal -> fractal_type == 2)
		julia(fractal);
	else if (fractal -> fractal_type == 3)
		burningship(fractal);
	mlx_put_image_to_window(fractal -> mlx, fractal -> win,
		fractal -> img.img_ptr, 0, 0);
	return (0);
}

void	iteration_changer(int key_code, t_fractal *fractal)
{
	mlx_clear_window(fractal -> mlx, fractal -> win);
	if (key_code == 69)
		fractal -> no_of_iterations += 10;
	if (key_code == 78)
		fractal -> no_of_iterations -= 10;
}

static	void	close_window(int key_code, t_fractal *fractal)
{
	if (key_code == 53)
	{
		mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
		mlx_destroy_window(fractal -> mlx, fractal -> win);
		free(fractal -> mlx);
		exit(0);
	}
}

int	key_movements(int key_code, t_fractal *fractal)
{
	mlx_clear_window(fractal -> mlx, fractal -> win);
	close_window(key_code, fractal);
	if (key_code == 0 || key_code == 123)
		fractal -> x_offset += -0.1;
	if (key_code == 2 || key_code == 124)
		fractal -> x_offset += 0.1;
	if (key_code == 1 || key_code == 125)
		fractal -> y_offset -= 0.1;
	if (key_code == 13 || key_code == 126)
		fractal -> y_offset += 0.1;
	iteration_changer(key_code, fractal);
	if (fractal -> fractal_type == 1)
		mandelbrot(fractal);
	else if (fractal -> fractal_type == 2)
		julia(fractal);
	else if (fractal -> fractal_type == 3)
		burningship(fractal);
	mlx_put_image_to_window(fractal -> mlx, fractal -> win,
		fractal -> img.img_ptr, 0, 0);
	return (0);
}
