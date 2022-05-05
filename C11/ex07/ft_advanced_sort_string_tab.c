/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:17:55 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 22:30:49 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
		if (cmp(tab[idx], tab[idx + 1]) > 0)
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
