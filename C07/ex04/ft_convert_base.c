/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:32:45 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/30 12:33:08 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa_base(long num, char *base);

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

int	is_invalid(char *base)
{
	int	map[256];
	int	idx;
	int	num;

	idx = 0;
	while (idx < 256)
	{
		map[idx] = 0;
		idx ++;
	}
	if (ft_strlen(base) <= 1)
		return (1);
	idx = 0;
	while (base[idx])
	{
		num = base[idx];
		if (num < 0)
			num += 256;
		map[num] += 1;
		if (map[num] > 1 || (base[idx] == '-' || base[idx] == '+')
			|| (base[idx] >= 9 && base[idx] <= 13) || base[idx] == 32)
			return (1);
		idx ++;
	}
	return (0);
}

int	find(char character, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (character == base[idx])
			return (idx);
		idx ++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	idx;
	int	result;
	int	size;

	sign = 1;
	idx = 0;
	result = 0;
	size = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (find(str[idx], base) != -1)
	{
		result = result * size + find(str[idx], base);
		idx ++;
	}
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;

	if (is_invalid(base_from) || is_invalid(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(num, base_to));
}
