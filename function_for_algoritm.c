/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_algoritm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:55:48 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:00:44 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		create_median_part_two(t_pushswap *var, int len, int med)
{
	while (len)
	{
		if (med > var->a[0])
		{
			if (var->a[0] < med / 2)
			{
				pb(var);
				if (med <= var->a[0])
					rr(var);
				else
					rb(var);
			}
			else
				pb(var);
			len--;
		}
		else
			ra(var);
	}
}

void			create_median(t_pushswap *var)
{
	int			med;
	int			len;
	int			x;

	x = 0;
	create_result_a(var);
	len = (var->size < 250 ? var->size_a / 2 : var->size_a / 6);
	while (x < var->size)
	{
		if (var->log[x] == 0)
			break ;
		x++;
	}
	var->log[x] = len;
	med = var->res_a[len];
	create_res_a_of_b(var, len);
	create_median_part_two(var, len, med);
}

void			create_sort_two(t_pushswap *var, int size)
{
	create_result_a(var);
	create_result_b(var, size);
	while (check_result_stack(var->a, var->size_a, var->res_a) ||
			check_result_stack(var->b, size, var->res_b))
	{
		if (var->a[0] > var->a[1] && var->b[0] < var->b[1])
			ss(var);
		else if (var->a[0] > var->a[1])
			sa(var);
		else if (var->b[0] < var->b[1])
			sb(var);
		else if (check_result_stack(var->a, var->size_a, var->res_a))
			rra(var);
		else if (check_result_stack(var->b, size, var->res_b))
		{
			rb(var);
			sb(var);
			rrb(var);
		}
	}
	while (size--)
		pa(var);
}

void			create_sort(t_pushswap *var)
{
	int			size;
	int			med;
	int			x;
	int			size_a;

	size = 0;
	x = 0;
	create_result_a(var);
	med = var->res_a[var->size_a / 2];
	size_a = var->size_a;
	while (var->size > 3 && x <= size_a && size < 3)
	{
		if (var->a[0] < med)
		{
			pb(var);
			size++;
		}
		else
			ra(var);
		x++;
	}
	create_sort_two(var, size);
}

int				record_push_a_plus(t_pushswap *var, int y, int *pos, int *flag)
{
	if (var->b[0] == var->res_a[y])
	{
		pa(var);
		if (*flag != 1)
			ra(var);
		if (*flag == 1)
			*pos -= 1;
		y++;
		*flag = 100;
	}
	return (y);
}
