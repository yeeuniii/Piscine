/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:56:18 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 17:09:22 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print(char *operators, int num)
{
	char	operator;

	operator = operators[0];
	if (operators[1] != '\0')
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (operator != '+' && operator != '-' && operator != '/'
		&& operator != '*' && operator != '%')
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (operator == '/' && num == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (operator == '%' && num == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}
