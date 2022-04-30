/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:18:32 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/27 22:02:31 by yeepark          ###   ########.fr       */
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

void	print(char **str, int num)
{
	int	idx;

	idx = 1;
	while (idx < num)
	{
		write(1, str[idx], ft_strlen(str[idx]));
		write(1, "\n", 1);
		idx ++;
	}
}

int	main(int argc, char **argv)
{
	int		idx;
	int		num;
	char	*tmp;

	idx = 1;
	num = argc;
	while (idx < argc - 1)
	{
		if (ft_strcmp(argv[idx], argv[idx + 1]) > 0)
		{
			tmp = argv[idx + 1];
			argv[idx + 1] = argv[idx];
			argv[idx] = tmp;
		}
		if (idx == argc - 2)
		{
			argc --;
			idx = 0;
		}
		idx ++;
	}
	print(argv, num);
}
