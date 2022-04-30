/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:36:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/27 16:51:49 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char board[], int col)
{
	int	idx;

	idx = 0;
	while (idx < col)
	{
		if (board[idx] == board[col])
			return (0);
		if (board[idx] + idx == board[col] + col)
			return (0);
		if (board[idx] - idx == board[col] - col)
			return (0);
		idx ++;
	}
	return (1);
}

void	make_board(char board[], int col, int *count)
{
	if (check(board, col))
	{
		if (col == 9)
		{
			write(1, board, 10);
			write(1, "\n", 1);
			*count += 1;
			return ;
		}
		else
		{
			board[col + 1] = '0';
			make_board(board, col + 1, count);
		}
	}
	if (board[col] < '9')
	{
		board[col] += 1;
		make_board(board, col, count);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	board[10];

	board[0] = '0';
	count = 0;
	make_board(board, 0, &count);
	return (count);
}
