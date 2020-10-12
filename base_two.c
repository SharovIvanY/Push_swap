/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:55:06 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:55:07 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pb(t_pushswap *var)
{
	int x;
	int i;

	change_name_functions(var, "pb\n");
	i = 0;
	if (var->size_a == 0)
		return ;
	x = var->a[i];
	while (i + 1 < var->size_a)
	{
		var->a[i] = var->a[i + 1];
		i++;
	}
	var->size_a -= 1;
	i = var->size_b;
	while (i - 1 >= 0)
	{
		var->b[i] = var->b[i - 1];
		i--;
	}
	var->b[0] = x;
	var->size_b += 1;
	if (var->flag_v)
		out_two_mass(var);
}

void		ra(t_pushswap *var)
{
	int x;
	int i;

	if (var->flag_functions == 0)
		change_name_functions(var, "ra\n");
	i = 0;
	if (var->size_a <= 1)
		return ;
	x = var->a[0];
	while (i + 1 < var->size_a)
	{
		var->a[i] = var->a[i + 1];
		i++;
	}
	var->a[var->size_a - 1] = x;
	if (var->flag_v)
		out_two_mass(var);
}

void		rb(t_pushswap *var)
{
	int x;
	int i;

	if (var->flag_functions == 0)
		change_name_functions(var, "rb\n");
	i = 0;
	if (var->size_b <= 1)
		return ;
	x = var->b[0];
	while (i < var->size_b)
	{
		var->b[i] = var->b[i + 1];
		i++;
	}
	var->b[var->size_b - 1] = x;
	if (var->flag_v)
		out_two_mass(var);
}

void		rr(t_pushswap *var)
{
	change_name_functions(var, "rr\n");
	var->flag_functions = 1;
	ra(var);
	rb(var);
	var->flag_functions = 0;
}

void		rra(t_pushswap *var)
{
	int x;
	int i;

	if (var->flag_functions == 0)
		change_name_functions(var, "rra\n");
	i = var->size_a - 1;
	if (var->size_a <= 1)
		return ;
	x = var->a[i];
	while (i - 1 >= 0)
	{
		var->a[i] = var->a[i - 1];
		i--;
	}
	var->a[0] = x;
	if (var->flag_v)
		out_two_mass(var);
}
