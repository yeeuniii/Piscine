/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:19:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/17 17:16:40 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	std;
	int	new;
	int	old;

	idx = 1;
	std = 0;
	while (std < size)
	{
		while (idx < size)
		{
			if (tab[std] > tab[idx])
			{
				new = tab[idx];
				old = tab[std];
				tab[std] = new;
				tab[idx] = old;
			}
			idx ++;
		}
		std ++;
		if (idx == size)
			idx = std + 1;
	}
}
