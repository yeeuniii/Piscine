/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:31:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/24 16:19:09 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count1(char *arr, int num)
{
	int	idx;
	int	count;
	int	pos;
	int	max;

	idx = 0;
	count = 1;
	pos = num;
	max = arr[pos];
	while (idx < 3)
	{
		pos += 4;
		if (max < arr[pos])
		{
			max = arr[pos];
			count ++;
		}
		idx ++;
	}
	return (count);
}

int	count2(char *arr, int num)
{
	int	idx;
	int	count;
	int	pos;
	int	max;

	num %= 4;
	idx = 0;
	count = 1;
	pos = 12 + num;
	max = arr[pos];
	while (idx < 3)
	{
		pos -= 4;
		if (max < arr[pos])
		{
			max = arr[pos];
			count ++;
		}
		idx ++;
	}
	return (count);
}

int	count3(char *arr, int num)
{
	int	idx;
	int	count;
	int	pos;
	int	max;

	num %= 4;
	idx = 0;
	count = 1;
	pos = num * 4;
	max = arr[pos];
	while (idx < 3)
	{
		pos ++;
		if (max < arr[pos])
		{
			max = arr[pos];
			count ++;
		}
		idx ++;
	}
	return (count);
}

int	count4(char *arr, int num)
{
	int	idx;
	int	count;
	int	pos;
	int	max;

	num %= 4;
	idx = 0;
	count = 1;
	pos = num * 4 + 3;
	max = arr[pos];
	while (idx < 3)
	{
		pos --;
		if (max < arr[pos])
		{
			max = arr[pos];
			count ++;
		}
		idx ++;
	}
	return (count);
}

int	count(char *arr, int num)
{
	int	sol;

	sol = 0;
	if (num >= 0 && num <= 3)
		sol = count1(arr, num);
	if (num >= 4 && num <= 7)
		sol = count2(arr, num);
	if (num >= 8 && num <= 11)
		sol = count3(arr, num);
	if (num >= 12 && num <= 15)
		sol = count4(arr, num);
	return (sol);
}
