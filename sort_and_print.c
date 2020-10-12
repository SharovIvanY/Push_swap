/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:57:26 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:10:15 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		max(const int *m, int size)
{
	int x;
	int max;

	x = 0;
	max = 0;
	while (x < size)
	{
		if (max < m[x])
			max = m[x];
		x++;
	}
	return (max);
}

static void		out_two_mass_two(t_pushswap *var, int size_a, int size_b,
		int num)
{
	int x;

	x = 0;
	while (size_a > 0 || size_b > 0)
	{
		if (size_a-- > 0)
			if (var->flag_colour)
				ft_printf("|%s%*d%s|", FR_GREEN, num, var->a[x], DEFAULT);
			else
				ft_printf("|%*d|", num, var->a[x]);
		else
			ft_printf("%*s", num + 2, "");
		if (size_b-- > 0)
			if (var->flag_colour)
				ft_printf("|%s%-*d%s|", FR_BYELLOW, num, var->b[x], DEFAULT);
			else
				ft_printf("|%-*d|", num, var->b[x]);
		else
			ft_printf("%*s", num + 2, "");
		ft_printf("\n");
		x++;
	}
}

void			out_two_mass(t_pushswap *var)
{
	int size_a;
	int size_b;
	int num;

	num = ft_power((unsigned long)max(var->res, var->size), 10);
	size_a = var->size_a;
	size_b = var->size_b;
	if (var->flag_colour)
		ft_printf("%s|%*s||%-*s|%s\n", FR_RED, num, "A", num, "B", DEFAULT);
	else
		ft_printf("|%*s||%-*s|\n", num, "A", num, "B");
	out_two_mass_two(var, size_a, size_b, num);
}

void			sort_res_number(t_pushswap *var)
{
	int			x;
	int			size;

	size = var->size;
	x = 0;
	while (x < size)
	{
		if (x + 1 < size && ft_swap(&x, var->numbers))
			continue;
		x++;
	}
	x = 0;
	while (x < size)
	{
		var->res[x] = x;
		x++;
	}
	if (var->flag_v)
		out_two_mass(var);
}

void			create_stack_index(t_pushswap *var)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (y < var->size)
	{
		if (var->numbers[y] == var->res[x])
		{
			var->a[y] = x;
			x = 0;
			y++;
			continue;
		}
		x++;
		if (x > var->size)
			break ;
	}
}
