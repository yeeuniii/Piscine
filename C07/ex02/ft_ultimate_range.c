/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:19:34 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/28 12:41:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	idx;
	int	*arr;

	size = max - min;
	idx = 0;
	if (size <= 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	while (idx < size)
	{
		arr[idx] = min;
		idx ++;
		min ++;
	}
	*range = arr;
	return (size);
}
//#include <stdio.h>
//int	main()
//{
// printf("-------ex02-------\n\n");
//    int	*ex02_arr1;
//    int	*ex02_arr2;
//    int	*ex02_arr3;
//	int size1 = ft_ultimate_range(&ex02_arr1, 5, 10);
//    int size2 = ft_ultimate_range(&ex02_arr2, -4, 10);
//    int size3 = ft_ultimate_range(&ex02_arr3, 10, 1);
//    
//    printf("min : 5, max : 10, size : %d\n", size1);
//	for (int i = 0; i < size1 ; i++)
//	{
//		printf("%d ", ex02_arr1[i]);
//	}
//    printf("\n\n");
//    printf("min : -4, max : 10, size : %d\n", size2);
//	for (int i = 0; i < size2 ; i++)
//	{
//		printf("%d ", ex02_arr2[i]);
//	}
//    printf("\n\n");
//    printf("min : 10, max : 1, size : %d\n", size3);
//	printf("%p ", ex02_arr3);
//    printf("\n\n");
//    free(ex02_arr1);
//    free(ex02_arr2);
//    free(ex02_arr3);
//}
