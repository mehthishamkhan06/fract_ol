#include "fractol.h"

int main(int argc, char*argv[])
{
    t_fractal fractal;
    if (argc > 1 && argc < 5)
    {
        check_fractol(argc, argv, &fractal);
        if (fractal.fractal_type == 1)
        {
            initialize_fractal(&fractal);
            mandelbrot(&fractal);
        }
        else if (fractal.fractal_type == 2)
        {
            initialize_fractal(&fractal);
            julia(&fractal);
        }
        else if (fractal.fractal_type == 3)
        {
            initialize_fractal(&fractal);
            burningship(&fractal);
        }
        mlx_key_hook(fractal.win, key_movements, &fractal);
        mlx_mouse_hook(fractal.win, mouse_movements, &fractal);
        mlx_hook(fractal.win, 17, 0, exit, &fractal);
        mlx_loop(fractal.mlx);
    }
    else
    {
        printf("Usage: ./fractol [mandelbrot/julia] [re] [im]\n");
        return (1);
    }
    return (0);
}
