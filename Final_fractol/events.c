#include "fractol.h"

int mouse_movements(int mouse_code, int x, int y, t_fractal *fractal)
{
    mlx_clear_window(fractal -> mlx, fractal -> win);
    if (mouse_code == 5)
        fractal -> view *= 1.1;
    else if (mouse_code == 4)
        fractal -> view /= 1.1;
	if (fractal -> fractal_type == 1)
		mandelbrot(fractal);
	else if (fractal -> fractal_type == 2)
		julia(fractal);
	else if (fractal -> fractal_type == 3)
		burningship(fractal);
   mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);
   return (0);
}

int key_movements(int key_code, t_fractal *fractal)
{
    mlx_clear_window(fractal -> mlx, fractal -> win);
    if (key_code == 53)
    {
        mlx_destroy_window(fractal -> mlx, fractal -> win);
        exit(0);
    }
    if (key_code == 0 || key_code == 123)
        fractal -> x_offset += -0.1;
	if (key_code == 2 || key_code == 124)
        fractal -> x_offset += 0.1;
    if (key_code == 1 || key_code == 125)
        fractal -> y_offset += 0.1;
    if (key_code == 13 || key_code == 126)
        fractal -> y_offset += -0.1;
	if (fractal -> fractal_type == 1)
		mandelbrot(fractal);
	else if (fractal -> fractal_type == 2)
		julia(fractal);
	else if (fractal -> fractal_type == 3)
		burningship(fractal);
   mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);
   return (0);
}
