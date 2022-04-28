/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:46:37 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/28 12:40:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
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
		return (0);
	while (idx < size)
	{
		arr[idx] = min;
		min ++;
		idx ++;
	}
	return (arr);
}

////#include <stdio.h>
////int	main()
////{
////  //ex01
////    printf("-------ex01-------\n\n");
////    int *ex01_arr1;
////    int *ex01_arr2;
////    int *ex01_arr3;
////    printf("min : 1, max : 10\n");
////    ex01_arr1 = ft_range(1, 10);
////    for(int i = 0; i < 9; i++)
////    {
////        printf("%d ", ex01_arr1[i]);
////    }
////    printf("\n\n");
//    printf("min : 10, max : 1\n");
//    ex01_arr2 = ft_range(1, 0);
//    printf("%p ", ex01_arr2);
//    printf("\n\n");
//    printf("min : -25, max : -10\n");
//    ex01_arr3 = ft_range(-25, -10);
//    for(int i = 0; i < 15; i++)
//    {
//        printf("%d ", ex01_arr3[i]);
//    }
//    printf("\n\n");
//    free(ex01_arr1);
//    free(ex01_arr2);
//    free(ex01_arr3);
//}
