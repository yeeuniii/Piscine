#include <unistd.h>
#include <stdio.h>
int	ft_atoi(char *str)
{
	int	sign = 1;
	int	res = 0;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-')
		sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str ++;
	}
	return (res * sign);
}

int	is_prime(int num)
{
	int divisor = 2;

	if (num < 2)
		return (0);
	while (divisor <= num / divisor)
	{
		if (!(num % divisor))
			return (0);
		divisor ++;
	}
	return (1);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c =  nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	num;
	int res = 0;
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	num = ft_atoi(argv[1]);
	if (num <= 1)	
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (num)
	{
		if (is_prime(num))
		{
			res += num;
			printf("%d\n", num);
		}
		num --;
	}
	ft_putnbr(res);
	return (0);
}
