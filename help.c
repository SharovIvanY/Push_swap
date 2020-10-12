/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:56:55 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:56:56 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_duplicate(t_pushswap *var)
{
	int		x;
	int		y;
	int		num;

	x = 0;
	y = 0;
	num = 0;
	while (y < var->size)
	{
		if (var->numbers[y] == var->numbers[x])
		{
			num++;
			if (num == 2)
				return (1);
		}
		x++;
		if (x == var->size)
		{
			num = 0;
			y++;
			x = 0;
		}
	}
	return (0);
}

int			while_space(const char *str)
{
	int		x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '\f' || str[x] == '\n' || str[x] == '\r' ||
				str[x] == '\t' || str[x] == '\v' || str[x] == ' ' || str[x]
				== '+')
			x++;
		else
			break ;
	}
	return (x);
}

int			error(void)
{
	ft_printf("Error\n");
	return (1);
}

int			check_char_stack(char ch)
{
	if (ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v'
			|| ch == ' ' || ch == '+')
		return (0);
	return (1);
}
