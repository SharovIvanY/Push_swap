/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:55:31 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:59:44 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_result_stack_complite(t_pushswap *var)
{
	int size;
	int x;

	x = 0;
	size = var->size;
	if (size != var->size_a)
		return (0);
	while (x < size)
	{
		if (var->res[x] != var->a[x])
			return (0);
		x++;
	}
	return (1);
}

int			check_result_stack_a(t_pushswap *var)
{
	int x;

	x = 0;
	while (x < var->size_a)
	{
		if (var->a[x] != var->res_a[x])
			return (1);
		x++;
	}
	return (0);
}

int			check_result_stack(const int *a, int size, const int *res_a)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (a[x] != res_a[x])
			return (1);
		x++;
	}
	return (0);
}

int			while_search(int *massive, int size, int num)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (num == massive[x])
			return (1);
		x++;
	}
	return (0);
}

int			while_search_num_pos(int *massive, int size, int num)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (num == massive[x])
			return (x);
		x++;
	}
	return (x);
}
