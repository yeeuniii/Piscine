/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:21:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 20:38:57 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int	idx;

	idx = 0;
	while (str1[idx] || str2[idx])
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		idx ++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		len;
	int		idx;
	char	*tmp;

	len = 0;
	idx = 0;
	while (tab[len])
		len ++;
	while (idx < len - 1)
	{
		if (ft_strcmp(tab[idx], tab[idx + 1]) > 0)
		{
			tmp = tab[idx];
			tab[idx] = tab[idx + 1];
			tab[idx + 1] = tmp;
		}
		idx ++;
		if (idx == len - 1)
		{
			len --;
			idx = 0;
		}
	}
}
