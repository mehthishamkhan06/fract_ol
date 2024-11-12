#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_fractal
{
    void	*mlx;
    int     fractal_type;
    void	*win;
    void	*img;
    void    *pixel_ptr;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int     no_of_iterations;
    int     escape_value;
    double    x;
    double    y;
}	t_fractal;

typedef struct s_complex
{
    double	re;
    double	im;
}	t_complex;


void    malloc_error(void);
void    check_fractol(int ac, char *argv[], t_fractal *fractal);
void    initialize_fractal(t_fractal *fractal);

/*
Maths
*/
t_complex    complex_add(t_complex a, t_complex b);
t_complex    complex_square(t_complex a);

#endif