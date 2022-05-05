/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:41:23 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/04 23:22:38 by joohpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

t_map		find_square(t_map map);
t_square	get_square(t_map map, int *coordinate);
t_map		fill(t_map map);
int			ft_atoi(char *str);

void	read_console()
{
	char	c;
	char	*str;
	int		fd;
	int		size;

	fd = open(".customMap", O_RDWR | O_APPEND | O_CREAT | O_TRUNC, "0644");
	size = 0;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			write(fd, "\n", 1);
			break ;
		}
		write(fd, &c, 1); 
		size ++;
	}
	close(fd);
	fd = open(".customMap", O_RDWR | O_APPEND);
	str = malloc(sizeof(char) * (size + 1));
	read(fd, str, size);
	size = size - 3;
	str[size] = '\0';
	size = ft_atoi(str);
	while (size > 0)
	{
		while (read(0, &c, 1))
		{
			if (c == '\n')
			{
				write(fd, "\n", 1);
				break ;
			}
			write(fd, &c, 1);
		}
		size--;
	}
	close(fd);
}

char	*read_file(int fd)
{
	int		size;
	char	tmp[1];
	char	*str;

	size = 0;
	while (read(fd, tmp, 1))
		size ++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		exit(1);
	read(fd + 1, str, size);
	str[size] = '\0';
	return (str);
}

void	print_map(t_map map)
{
	int	idx;

	idx = 0;
	while (idx < map.row)
	{
		write(1, map.strs[idx], map.col);
		write(1, "\n", 1);
		idx ++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		idx;
	char	*str;
	t_map	map;

	idx = 1;
	if (argc == 1)
	{
		read_console();
		argv[1] = malloc(sizeof(char) * 11);
		argv[1] = ".customMap";
		argc++;
	}
	while (idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		open(argv[idx], O_RDONLY);
		if (fd == -1)
		{
			write(2, "map error\n", 10);
			idx ++;
			continue ;
		}
		str = read_file(fd);
		close(fd);
		close(fd + 1);
		map = check2(str);
		if (!map.valid)
		{
			write(2, "map error\n", 10);
			idx ++;
			continue ;
		}
		idx ++;
		map = find_square(map);
		map = fill(map);
		print_map(map);
		free(map.strs);
	}
	return (0);
}
