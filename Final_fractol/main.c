#include "fractol.h"


int main(int argc, char*argv[])
{
    t_fractal fractal;
    if (argc > 1 && argc < 5)
    {
        check_fractol(argc, argv, &fractal);
        initialize_fractal(&fractal);
        // draw_fractal(&fractal);
        mlx_loop(fractal.mlx);
    }
    else
    {
        printf("Usage: ./fractol [mandelbrot/julia] [re] [im]\n");
        return (1);
    }
    return (0);

}