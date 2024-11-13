#include "fractol.h"

void    check_fractol(int ac, char *argv[], t_fractal *fractal)
{
    if (ac == 2 && (strcmp(argv[1], "mandelbrot") == 0))
        fractal -> fractal_type = 1;
    else if (ac == 4 && (strcmp(argv[1], "julia") == 0))
    {
        fractal -> fractal_type = 2;
        fractal -> x = atof(argv[2]);
        fractal -> y = atof(argv[3]);
    }
    else if (ac == 2 && (strcmp(argv[1], "burningship") == 0))
        fractal -> fractal_type = 3;
    else
    {
        printf("Usage: ./fractol [mandelbrot/julia] [re] [im]\n");
        exit (1);
    }
}

void initialize_fractal(t_fractal *fractal)
{
	fractal->view = 1;
    fractal -> no_of_iterations = 70;
    fractal -> x_offset = 0.0;
    fractal -> y_offset = 0.0;
    fractal -> escape_value = 4;
    fractal -> mlx = mlx_init();
    fractal -> win = mlx_new_window(fractal -> mlx, WIDTH, HEIGHT, "Fractol");
    // if (!fractal -> win)
    // {
    //     mlx_destroy_display(fractal -> mlx);
    //     free(fractal -> mlx);
    //     malloc_error();
    // }
    fractal -> img.img_ptr = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
    if (!fractal -> img.img_ptr)
    {
        mlx_destroy_window(fractal -> mlx, fractal -> win);
        // mlx_destroy_display(fractal -> mlx);
        free(fractal -> mlx);
        malloc_error();
    }
    fractal -> img.pixels_ptr = mlx_get_data_addr(fractal -> img.img_ptr, &fractal -> img.bpp, &fractal -> img.line_len, &fractal -> img.endian);
    if (!fractal -> img.pixels_ptr)
    {
        mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
        mlx_destroy_window(fractal -> mlx, fractal -> win);
        // mlx_destroy_display(fractal -> mlx);
        free(fractal -> mlx);
        malloc_error();
    }
}
