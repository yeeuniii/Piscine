/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:43:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/17 17:16:19 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	num1;
	int	num2;

	index = 0;
	while (index < size / 2)
	{
		num1 = tab[index];
		num2 = tab[size - index - 1];
		tab[index] = num2;
		tab[size - index - 1] = num1;
		index ++;
	}
}
