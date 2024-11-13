#include "fractol.h"

void my_mlx_pixel_put(int x, int y, t_img *data, int color)
{
	char	*dst;

	dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex    complex_add(t_complex a, t_complex b)
{
    t_complex    c;

    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return (c);
}

t_complex   complex_square(t_complex a)
{
    t_complex    c;

    c.re = (a.re * a.re) - (a.im * a.im);
    c.im = 2 * a.re * a.im;
    return (c);
}