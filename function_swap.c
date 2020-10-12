/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:56:49 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:56:51 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_swap(int *x, int *mas)
{
	int swap;

	if (mas[*x] > mas[*x + 1])
	{
		swap = mas[*x];
		mas[*x] = mas[*x + 1];
		mas[*x + 1] = swap;
		*x = 0;
		return (1);
	}
	return (0);
}

int				ft_swap_b(int *x, int *mas)
{
	int swap;

	if (mas[*x] < mas[*x + 1])
	{
		swap = mas[*x];
		mas[*x] = mas[*x + 1];
		mas[*x + 1] = swap;
		*x = 0;
		return (1);
	}
	return (0);
}
