/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:25:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 15:42:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;
	int	sorted;

	idx = 1;
	sorted = 0;
	while (!sorted && idx < length)
	{
		if (f(tab[idx - 1], tab[idx]) > 0)
			sorted = -1;
		if (f(tab[idx - 1], tab[idx]) < 0)
			sorted = 1;
		idx ++;
	}
	while (idx < length)
	{
		if (sorted == 1 && f(tab[idx - 1], tab[idx]) > 0)
			return (0);
		if (sorted == -1 && f(tab[idx - 1], tab[idx]) < 0)
			return (0);
		idx ++;
	}
	return (1);
}
