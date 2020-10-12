/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:55:14 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:55:19 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rrb(t_pushswap *var)
{
	int x;
	int i;

	if (var->flag_functions == 0)
		change_name_functions(var, "rrb\n");
	i = var->size_b - 1;
	if (var->size_b <= 1)
		return ;
	x = var->b[i];
	while (i - 1 >= 0)
	{
		var->b[i] = var->b[i - 1];
		i--;
	}
	var->b[0] = x;
	if (var->flag_v)
		out_two_mass(var);
}

void		rrr(t_pushswap *var)
{
	change_name_functions(var, "rrr\n");
	var->flag_functions = 1;
	rra(var);
	rrb(var);
	var->flag_functions = 0;
}
