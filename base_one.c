/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:54:56 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:54:58 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		change_name_functions(t_pushswap *var, char *str)
{
	char *temp;
	char *temp2;

	var->max_func++;
	if (var->flag_functions == 1)
		return ;
	temp = ft_strdup(var->functions);
	temp2 = ft_strdup(str);
	free(var->functions);
	var->functions = ft_strjoin(temp, temp2);
	free(temp);
	free(temp2);
}

void		sa(t_pushswap *var)
{
	int x;

	if (var->flag_functions == 0)
		change_name_functions(var, "sa\n");
	if (var->size_a <= 1)
		return ;
	x = var->a[0];
	var->a[0] = var->a[1];
	var->a[1] = x;
	if (var->flag_v)
		out_two_mass(var);
}

void		sb(t_pushswap *var)
{
	int x;

	if (var->flag_functions == 0)
		change_name_functions(var, "sb\n");
	if (var->size_b <= 1)
		return ;
	x = var->b[0];
	var->b[0] = var->b[1];
	var->b[1] = x;
	if (var->flag_v)
		out_two_mass(var);
}

void		ss(t_pushswap *var)
{
	change_name_functions(var, "ss\n");
	var->flag_functions = 1;
	sa(var);
	sb(var);
	var->flag_functions = 0;
	if (var->flag_v)
		out_two_mass(var);
}

void		pa(t_pushswap *var)
{
	int x;
	int i;

	change_name_functions(var, "pa\n");
	i = 0;
	if (var->size_b == 0)
		return ;
	x = var->b[i];
	while (i + 1 < var->size_b)
	{
		var->b[i] = var->b[i + 1];
		i++;
	}
	var->size_b -= 1;
	i = var->size_a;
	while (i - 1 >= 0)
	{
		var->a[i] = var->a[i - 1];
		i--;
	}
	var->a[0] = x;
	var->size_a += 1;
	if (var->flag_v)
		out_two_mass(var);
}
