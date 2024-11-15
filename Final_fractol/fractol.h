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

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

/*
 * COLORS
*/
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
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
int			ft_isdigit(int c);
/*
Errors
*/

void		malloc_error(void);
void		digit_error(void);
void		over_flow_error(void);

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