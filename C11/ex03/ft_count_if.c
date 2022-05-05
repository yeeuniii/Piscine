/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:07:25 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/03 14:08:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(tab[idx]))
			count ++;
		idx ++;
	}
	return (count);
}
