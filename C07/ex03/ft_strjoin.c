/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:42:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/28 15:27:56 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

char	*ft_strcat(char *dest, char *str)
{
	int	idx;
	int	size;

	idx = 0;
	size = ft_strlen(dest);
	while (str[idx])
	{
		dest[size + idx] = str[idx];
		idx ++;
	}
	dest[size + idx] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		idx;

	idx = 0;
	len = 0;
	if (size == 0)
		return (0);
	while (idx < size)
	{
		len += ft_strlen(strs[idx]);
		idx ++;
	}
	len += ft_strlen(sep) * (size - 1);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	idx = 0;
	while (idx < size)
	{
		ft_strcat(str, strs[idx]);
		ft_strcat(str, sep);
		idx ++;
	}
	return (str);
}

//#include <stdio.h>
//int	main()
//{
//	printf("-------ex03-------\n\n");
//    char *ex03_arr1;
//    char *ex03_arr2;
//    char *ex03_arr3;
//	char *ex03_str[5];
//	
//	ex03_str[0] = "hello";
//	ex03_str[1] = "my";
//	ex03_str[2] = "name";
//	ex03_str[3] = "is";
//	ex03_str[4] = "yeepark!";
//	ex03_arr1 = ft_strjoin(5, ex03_str, " ");
//    ex03_arr2 = ft_strjoin(5, ex03_str, ".");
//    ex03_arr3 = ft_strjoin(5, ex03_str, "-");
//	printf("%s\n", ex03_arr1);
//    printf("%s\n", ex03_arr2);
//    printf("%s\n\n", ex03_arr3);
//    free(ex03_arr1);
//    free(ex03_arr2);
//    free(ex03_arr3);
//}
