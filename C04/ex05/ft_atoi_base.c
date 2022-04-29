/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:21:51 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/28 22:14:25 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size ++;
	return (size);
}

int	is_invalid(char *base, int size)
{
	int	idx;
	int	map[256];

	idx = 0;
	while (idx < 256)
	{
		map[idx] = 0;
		idx ++;
	}
	if (size <= 1)
		return (1);
	idx = 0;
	while (base[idx])
	{
		if (base[idx] == '-' || base[idx] == '+')
			return (1);
		if ((base[idx] >= 9 && base[idx] <= 13) || base[idx] == 32)
			return (1);
		map[(unsigned int)base[idx]] += 1;
		if (map[(unsigned int)base[idx]] > 1)
			return (1);
		idx ++;
	}
	return (0);
}

char	*process(char *str, int *sign)
{
	char	c;

	c = *str;
	while ((c >= 9 && c <= 13) || c == 32)
		c = *(++str);
	while (c == '-' || c == '+')
	{
		if (c == '-')
			(*sign)++;
		c = *(++str);
	}
	return (str);
}

int	find(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			return (idx);
		idx ++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	idx;
	int	size;
	int	sign;
	int	result;

	idx = 0;
	sign = 0;
	result = 0;
	size = ft_strlen(base);
	if (is_invalid(base, size))
		return (0);
	str = process(str, &sign);
	while (find(str[idx], base) != -1)
	{
		result = result * size + find(str[idx], base);
		idx ++;
	}
	if (sign % 2)
		result *= -1;
	return (result);
}
