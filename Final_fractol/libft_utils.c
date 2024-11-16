#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

static  int	max_onedec(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}
int ft_isdigit_str(char *str)
{
	int i;

	i = 0;
	if (max_onedec(str) > 1)
		return(1);
	if (str[0] == '+' || str[0] == '-')
    	i = 1;
	while(str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (1);
		i++;
	}
	return (0);
}