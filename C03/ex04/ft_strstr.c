/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:32:23 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/23 12:18:26 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && idx < n)
	{
		if (s1[idx] == s2[idx])
			idx ++;
		else
			return (s1[idx] - s2[idx]);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	size;
	int	check;

	i = 0;
	size = 0;
	check = 0;
	if (!(*to_find))
		return (str);
	while (to_find[size])
		size ++;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			check = ft_strncmp(str + i, to_find, size);
			if (check == 0)
				return (str + i);
		}
		i ++;
	}
	return (0);
}
