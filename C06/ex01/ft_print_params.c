/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:13:43 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/27 21:24:57 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

int	main(int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		write(1, argv[idx], ft_strlen(argv[idx]));
		write(1, "\n", 1);
		idx ++;
	}
}
