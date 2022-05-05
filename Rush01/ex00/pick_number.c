/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:27:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/24 22:21:23 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

char	*pick_number(char *str, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (str[i] >= '1' && str[i] <= '4')
			{
				result[j] = str[i];
				j ++;
			}
			else
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i ++;
	}
	if (j != 16)
		return (0);
	return (result);
}
