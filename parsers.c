/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:57:06 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:05:48 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_flags_two(const char *str, t_pushswap *var)
{
	int			x;

	x = 0;
	if (str[x] == '-')
	{
		while (str[++x])
		{
			if (str[x] == 'v')
				var->flag_v = 1;
			else if (str[x] == 's')
				var->flag_s = 1;
			else if (str[x] == 'i')
				var->flag_i = 1;
			else if (str[x] == 'h')
				var->flag_h = 1;
			else if (str[x] == 'x')
				var->flag_size = 1;
			else if (str[x] == 'c')
				var->flag_colour = 1;
			else if (str[x] >= '0' && str[x] <= '9')
				return (1);
		}
		return (2);
	}
	return (1);
}

int				parser_two(char **argv, int argc, t_pushswap *var)
{
	int			y;
	int			x;
	int			xx;
	long		num;
	int			len;

	xx = 0;
	y = check_flags_two(argv[1], var);
	while (y < argc)
	{
		x = 0;
		len = ft_strlen(argv[y]);
		while (x < len)
		{
			x += while_space(argv[y] + x);
			num = ft_atoi(argv[y] + x);
			var->numbers[xx++] = (int)num;
			x += ft_power2(num, 10) + 1;
			x += while_space(argv[y] + x);
		}
		y++;
	}
	return (0);
}

static int		parser_if(char *argv, int *size)
{
	int			x;
	int			err;

	x = 0;
	while (argv[x] != 0)
	{
		if (ft_isdigit(argv[x]) || argv[x] == '-')
		{
			x += (argv[x] == '-' && argv[x + 1] == '0' ? 1 : 0);
			if (argv[x] == '-' && !(argv[x + 1] >= '0' && argv[x + 1] <= '9'))
				return (-777);
			x += ft_power2(ft_atoi_err(argv + x, &err), 10);
			if (err == 1)
				return (-777);
			*size += 1;
		}
		else if (check_char_stack(argv[x]))
			return (-777);
		else
			x++;
	}
	return (x);
}

int				parser_check_flags(const char *str, int flag)
{
	int			x;

	x = 0;
	if (str[0] == '-' && flag == 1)
	{
		while (str[x])
		{
			if (str[x] >= '0' && str[x] <= '9')
				return (1);
			x++;
		}
		return (2);
	}
	return (1);
}

int				parser(char **argv, int argc, int flag)
{
	int			y;
	int			size;

	y = parser_check_flags(argv[1], flag) - 1;
	size = 0;
	while (++y < argc)
		if (parser_if(argv[y], &size) < 0)
			return (-777);
	return (size);
}
