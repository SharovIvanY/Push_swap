/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:56:35 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:02:04 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_struct(t_pushswap *var)
{
	free(var->functions);
	free(var->a);
	free(var->b);
	free(var->res);
	free(var->numbers);
	free(var->res_a);
	free(var->res_b);
	free(var->log);
	free(var);
}
