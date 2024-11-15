#include "fractol.h"

void	malloc_error(void)
{
	ft_putstr_fd("Error: malloc failed\n", 2);
	exit(0);
}


void	digit_error(void)
{
	ft_putstr_fd("Error: Please enter a valid digit\n", 2);
	exit(1);
}

void	over_flow_error(void)
{
	ft_putstr_fd("Error Please Look What You Have Given as an Argument\n", 2);
	exit(1);
}
