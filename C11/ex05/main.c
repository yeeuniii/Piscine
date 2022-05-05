/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:24:32 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 17:08:42 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		print(char *operators, int num);
void	calculate(char operator, int num1, int num2);

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str ++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	operator;

	if (argc != 4)
		return (0);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (print(argv[2], num2))
		return (0);
	operator = argv[2][0];
	calculate(operator, num1, num2);
	return (0);
}
