#include "fractol.h"


static	void	ft_atoi_overflow(size_t answer, int sign, char *str)
{
	if (answer > 2147483648 && sign == -1)
		over_flow_error();
	if (answer > INT_MAX && sign == 1)
		over_flow_error();
}
static	double	atodbl_continution(char *s, size_t integer_part, int sign)
{
	double	decimal_part;
	double	pow;

	decimal_part = 0;
	pow = 1;
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		decimal_part = decimal_part + (*s++ - 48) * pow;
	}
	return ((integer_part + decimal_part) * sign);
}
double	ft_atodbl(char *str)
{
	size_t	answer;
	size_t	temp_answer;
	int		sign;
	int		i;

	answer = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '.' )
	{
		if (!ft_isdigit(str[i]))
			digit_error();
		while (str[i] >= '0' && str[i] <= '9')
		{
			temp_answer = answer;
			answer = answer * 10 + str[i++] - '0';
			if (temp_answer > answer)
			over_flow_error();
		}
	}
	ft_atoi_overflow(answer, sign, str);
	if (str[i] == '.')
		return (atodbl_continution(&str[i], answer, sign));
	return (answer * sign);
}
