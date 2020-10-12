/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:57:01 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:05:16 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					ft_atoi_err(const char *str, int *err)
{
	long			ret;
	long			max_int;
	int				count;
	int				sign;

	ret = 0;
	count = 0;
	sign = 1;
	*err = 0;
	max_int = (str[count] == '-') ? (INT_MIN) : (INT_MAX);
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	while ((str[count] >= '0') && (str[count] <= '9') && (ret < max_int))
	{
		ret *= 10;
		ret = ret + (str[count++] - '0');
	}
	if (ret > max_int)
		*err = 1;
	return ((int)ret * sign);
}

int					ft_power2(long long int nb, int notation)
{
	long long int	res;

	res = 0;
	if (nb < 0)
		res++;
	if (!nb)
		return (1);
	while (nb)
	{
		nb = nb / notation;
		res++;
	}
	return (res);
}
