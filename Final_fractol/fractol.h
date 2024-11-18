/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:09:24 by mohkhan           #+#    #+#             */
/*   Updated: 2024/11/18 16:09:25 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

# define WIDTH 400
# define HEIGHT 400
# define MAX_ITER 100

/*
 * COLORS
*/
# define BLACK       0x000000 
# define WHITE       0xFFFFFF
# define RED         0xFF0000  
# define GREEN       0x00FF00  
# define BLUE        0x0000FF  
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600  
# define PSYCHEDELIC_PURPLE 0x660066 
# define AQUA_DREAM      0x33CCCC  
# define HOT_PINK        0xFF66B2  
# define ELECTRIC_BLUE   0x0066FF 
# define LAVA_RED        0xFF3300  

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		ln_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx;
	int		fractal_type;
	void	*win;
	void	*pixels_ptr;
	char	*addr;
	int		no_of_iterations;
	int		escape_value;
	double	x;
	double	y;
	double	shift_x;
	double	shift_y;
	t_img	img;
	double	view;
	double	x_offset;
	double	y_offset;
}	t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

/*
Libft
*/
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit_str(char *str);
/*
Errors
*/

void		malloc_error(void);
void		digit_error(void);
void		over_flow_error(void);
void		ft_error(void);
int			destroy_fractal(t_fractal *fractal);
/*
Fractol
*/
void		check_and_init_fractol(int ac, char *argv[], t_fractal *fractal);

/*
Maths
*/
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
void		my_mlx_pixel_put(int x, int y, t_img *data, int color);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);

/*
mandelbrot
*/
void		mandelbrot(t_fractal *fractal);
void		julia(t_fractal *fractal);
double		ft_atodbl(char *str);
void		burningship(t_fractal *fractal);

/*
Events
*/		
int			key_movements(int key_code, t_fractal *fractal);
int			mouse_movements(int mouse_code, int x, int y, t_fractal *fractal);
int			mouse_zoom(int button, int x, int y, t_fractal *fractal);
int			mouse_move(int x, int y, t_fractal *fractal);
double		scale(double num, double new_min, double new_max);

#endif
