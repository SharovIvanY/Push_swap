/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_initialization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:56:43 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:02:49 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				last_med(t_pushswap *var, int flag)
{
	int			x;
	int			med;

	x = 0;
	med = 0;
	while (1)
	{
		if (x > 0 && var->log[x] == 0)
		{
			if (flag == 1)
				var->log[x - 1] = 0;
			break ;
		}
		else
			med = var->log[x];
		x++;
	}
	return (med);
}

static void		ft_full_zero(int *mas, int size)
{
	int			x;

	x = 0;
	while (x < size)
		mas[x++] = 0;
}

static void		create_pushswap_two(t_pushswap *new, int size)
{
	new->size = size;
	new->size_a = size;
	new->size_b = 0;
	new->max_func = 0;
	new->flag_functions = 0;
	new->flag_v = 0;
	new->flag_s = 0;
	new->flag_i = 0;
	new->flag_h = 0;
	new->flag_colour = 0;
	new->flag_size = 0;
}

t_pushswap		*create_pushswap(int size)
{
	t_pushswap	*new;

	new = (t_pushswap*)malloc(sizeof(t_pushswap));
	new->res = (int*)malloc(sizeof(int) * size);
	new->numbers = (int*)malloc(sizeof(int) * size);
	new->a = (int*)malloc(sizeof(int) * size);
	new->res_a = (int*)malloc(sizeof(int) * size);
	new->b = (int*)malloc(sizeof(int) * size);
	new->res_b = (int*)malloc(sizeof(int) * size);
	new->log = (int*)malloc(sizeof(int) * size);
	ft_full_zero(new->res, size);
	ft_full_zero(new->numbers, size);
	ft_full_zero(new->a, size);
	ft_full_zero(new->res_a, size);
	ft_full_zero(new->b, size);
	ft_full_zero(new->res_b, size);
	ft_full_zero(new->log, size);
	new->functions = ft_strnew(1);
	create_pushswap_two(new, size);
	return (new);
}
