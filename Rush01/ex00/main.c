/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:27:42 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/24 22:26:46 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error(void);
char	*pick_number(char *str, char *result);
int		run(char *numbers);

int	main(int argc, char **argv)
{
	char	result[17];
	char	*numbers;

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	numbers = pick_number(argv[1], result);
	if (!numbers)
	{
		print_error();
		return (0);
	}
	if (!run(numbers))
		print_error();
	return (0);
}
