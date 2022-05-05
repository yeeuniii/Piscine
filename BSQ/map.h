/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:00:09 by yeepark           #+#    #+#             */
/*   Updated: 2022/05/04 23:10:46 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "square.h"

typedef struct s_map
{
	int			row;
	int			col;
	int			valid;
	char		empty;
	char		obstacle;
	char		full;
	char		**strs;
	t_square	square;
}	t_map;

t_map	check2(char *str);

#endif
