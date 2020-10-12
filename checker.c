/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:55:23 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 16:59:13 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_error(char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		return (0);
	else if (ft_strcmp(line, "pb") == 0)
		return (0);
	else if (ft_strcmp(line, "sa") == 0)
		return (0);
	else if (ft_strcmp(line, "sb") == 0)
		return (0);
	else if (ft_strcmp(line, "ss") == 0)
		return (0);
	else if (ft_strcmp(line, "ra") == 0)
		return (0);
	else if (ft_strcmp(line, "rb") == 0)
		return (0);
	else if (ft_strcmp(line, "rr") == 0)
		return (0);
	else if (ft_strcmp(line, "rra") == 0)
		return (0);
	else if (ft_strcmp(line, "rrb") == 0)
		return (0);
	else if (ft_strcmp(line, "rrr") == 0)
		return (0);
	return (1);
}

void			accept(char *line, t_pushswap *var)
{
	if (ft_strcmp(line, "pa") == 0)
		pa(var);
	else if (ft_strcmp(line, "pb") == 0)
		pb(var);
	else if (ft_strcmp(line, "sa") == 0)
		sa(var);
	else if (ft_strcmp(line, "sb") == 0)
		sb(var);
	else if (ft_strcmp(line, "ss") == 0)
		ss(var);
	else if (ft_strcmp(line, "ra") == 0)
		ra(var);
	else if (ft_strcmp(line, "rb") == 0)
		rb(var);
	else if (ft_strcmp(line, "rr") == 0)
		rr(var);
	else if (ft_strcmp(line, "rra") == 0)
		rra(var);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(var);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(var);
}

int				create_command(t_pushswap *var)
{
	char		*line;

	while (1)
	{
		if (get_next_line(0, &line) == 0)
		{
			line = ft_strnew(1);
			ft_memdel((void**)&line);
			return (0);
		}
		if (check_error(line))
		{
			ft_memdel((void**)&line);
			return (error());
		}
		accept(line, var);
		ft_memdel((void**)&line);
	}
}

static int		flags_print(t_pushswap *var, int flag)
{
	if (flag == 1)
	{
		if (check_result_stack_complite(var))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	if (var->flag_size)
		ft_printf("size stack = %d\n", var->size);
	if (var->flag_i)
		ft_printf("functions = %d\n", var->max_func);
	if (var->flag_h)
		ft_printf("musage: ./checker -vcix \"numbers\"\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_pushswap	*var;
	int			size;

	if (argc < 2 || (argc == 2 && parser_check_flags(argv[1], 1) == 2))
		ERROR;
	if ((size = parser(argv, argc, 1)) == -777)
		return (error());
	if (size == 0)
		ERROR;
	var = create_pushswap(size);
	if (parser_two(argv, argc, var) || check_duplicate(var))
	{
		free_struct(var);
		return (error());
	}
	create_result_res(var);
	create_stack_index(var);
	sort_res_number(var);
	if (create_command(var))
		return (flags_print(var, 0));
	flags_print(var, 1);
	free_struct(var);
	return (0);
}
