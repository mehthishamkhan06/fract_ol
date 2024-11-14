#include "fractol.h"
void    bonus_view(t_fractal *fractal, int mouse_x, int mouse_y, int flag)
{
	double	x;
	double	y;
	double	screen_x;
	double	screen_y;

	x = 0;
	y = 0;
	screen_x = 0;
	screen_y = 0;
	x = (scale(mouse_x, -2, 2) * fractal->view) + fractal->shift_x;
	y = (scale(mouse_y, 2, -2) * fractal->view) + fractal->shift_y;
	if (flag == 1)
		fractal->view /= 1.25;
	else if (flag == -1)
		fractal->view *= 1.25;
	screen_x = (scale(mouse_x, -2, 2) * fractal->view) + fractal->shift_x;
	screen_y = (scale(mouse_y, 2, -2) * fractal->view) + fractal->shift_y;
	fractal->shift_x += (x - screen_x);
	fractal->shift_y += (y - screen_y);
}

int mouse_movements(int mouse_code, int x, int y, t_fractal *fractal)
{
    mlx_clear_window(fractal -> mlx, fractal -> win);
    printf("x: %d, y: %d\n", x, y);
    mlx_mouse_get_pos(fractal -> win, &x, &y);
    if (mouse_code == 5)
        fractal -> view *= 1.1;
    if (mouse_code == 4)
        fractal -> view /= 1.1;
	printf("view: %f\n", fractal -> view);
    if (fractal -> fractal_type == 1)
		mandelbrot(fractal);
	else if (fractal -> fractal_type == 2)
		julia(fractal);
	else if (fractal -> fractal_type == 3)
		burningship(fractal);
   mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);
   return (0);
}
void    iteration_changer(int key_code, t_fractal *fractal)
{
    mlx_clear_window(fractal -> mlx, fractal -> win);
    if (key_code == 69)
        fractal -> no_of_iterations += 10;
    if (key_code == 78)
        fractal -> no_of_iterations -= 10;
}
int key_movements(int key_code, t_fractal *fractal)
{
    mlx_clear_window(fractal -> mlx, fractal -> win);
    if (key_code == 53)
    {
        mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
        mlx_destroy_window(fractal -> mlx, fractal -> win);
        // mlx_clear_display(fractal -> mlx);
        free(fractal -> mlx);
        exit(0);
    }
    if (key_code == 0 || key_code == 123)
        fractal -> x_offset += -0.1;
    printf("x_offset: %f\n", fractal -> x_offset);
	if (key_code == 2 || key_code == 124)
        fractal -> x_offset += 0.1;
    printf("x_offset minus: %f\n", fractal -> x_offset);
    if (key_code == 1 || key_code == 125)
        fractal -> y_offset -= 0.1;
    printf("y_offset: %f\n", fractal -> y_offset);
    if (key_code == 13 || key_code == 126)
        fractal -> y_offset += 0.1;
    printf("y_offset minus: %f\n", fractal -> y_offset);
    iteration_changer(key_code, fractal);
	if (fractal -> fractal_type == 1)
		mandelbrot(fractal);
	else if (fractal -> fractal_type == 2)
		julia(fractal);
	else if (fractal -> fractal_type == 3)
		burningship(fractal);
   mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);
   return (0);
}
