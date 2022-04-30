/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:01:33 by yeepark           #+#    #+#             */
/*   Updated: 2022/04/20 16:57:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_in_str(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')
		|| (str >= '0' && str <= '9'))
		return (1);
	return (0);
}

int	ft_is_uppercase(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	return (0);
}

int	ft_is_lowercase(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!ft_is_in_str(str[idx - 1]) || idx == 0)
		{
			if (ft_is_lowercase(str[idx]))
				str[idx] -= 32;
		}
		else if (ft_is_uppercase(str[idx]))
			str[idx] += 32;
		idx ++;
	}
	return (str);
}
