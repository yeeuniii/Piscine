/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:04:08 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/24 19:18:35 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *arr, char *numbers);

int	check_overlap(char *arr, int pos)
{
	int	idx;

	idx = 0;
	while (idx < pos)
	{
		if (idx / 4 == pos / 4)
		{
			if (arr[idx] == arr[pos])
				return (0);
		}
		if (idx % 4 == pos % 4)
		{
			if (arr[idx] == arr[pos])
				return (0);
		}
		idx ++;
	}
	return (1);
}

void	print_array(char *arr)
{
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		write(1, arr + idx, 1);
		if (idx % 4 != 3)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		idx += 1;
	}
}

int	check_next(char *arr, int pos, char *numbers)
{
	if (check_overlap(arr, pos))
	{
		if (pos == 15 && check(arr, numbers))
		{
			print_array(arr);
			return (1);
		}
		else
		{
			arr[pos + 1] = '1';
			if (check_next(arr, pos + 1, numbers))
				return (1);
		}
	}
	if (arr[pos] < '4')
	{
		arr[pos] += 1;
		if (check_next(arr, pos, numbers))
			return (1);
	}
	return (0);
}

int	run(char *numbers)
{
	char	arr[17];
	int		res;

	arr[0] = '1';
	res = check_next(arr, 0, numbers);
	return (res);
}
