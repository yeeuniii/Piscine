/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:31:32 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/24 22:03:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count(char *arr, int num);

int	check(char *arr, char *numbers)
{
	int	num;
	int	sol;

	num = 0;
	sol = 0;
	while (num < 16)
	{
		sol = count(arr, num);
		if (sol + '0' != numbers[num])
			return (0);
		num ++;
	}
	return (1);
}
