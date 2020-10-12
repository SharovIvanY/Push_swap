/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:57:20 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/13 17:07:49 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PUSH_SWAP_PUSH_SWAP_H
# define MY_PUSH_SWAP_PUSH_SWAP_H

# include "libftprintf/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define INT_MIN (2147483648)
# define INT_MAX (2147483647)

# define ERROR {ft_printf("usage: ./checker -vcix \"numbers\"\n"); return (0);}

typedef struct	s_pushswap
{
	int			*res;
	int			*numbers;
	int			*a;
	int			*res_a;
	int			*b;
	int			*res_b;
	int			*log;
	int			size;
	int			size_a;
	int			size_b;
	int			max_func;
	char		*functions;
	int			flag_functions;
	int			flag_v;
	int			flag_s;
	int			flag_i;
	int			flag_h;
	int			flag_colour;
	int			flag_size;
}				t_pushswap;

int				parser(char **argv, int argc, int flag);
void			change_name_functions(t_pushswap *var, char *str);
void			sa(t_pushswap *var);
void			sb(t_pushswap *var);
void			ss(t_pushswap *var);
void			pa(t_pushswap *var);
void			pb(t_pushswap *var);
void			ra(t_pushswap *var);
void			rb(t_pushswap *var);
void			rr(t_pushswap *var);
void			rra(t_pushswap *var);
void			rrb(t_pushswap *var);
void			rrr(t_pushswap *var);
int				check_result_stack_complite(t_pushswap *var);
int				check_result_stack(const int *a, int size, const int *res_a);
int				check_result_stack_a(t_pushswap *var);
int				while_search_num_pos(int *massive, int size, int num);
int				while_search(int *massive, int size, int num);
void			create_sort(t_pushswap *var);
void			create_median(t_pushswap *var);
int				record_push_a_plus(t_pushswap *var, int y, int *pos, int *flag);
void			create_go_to_stack_a(t_pushswap *var);
t_pushswap		*create_pushswap(int size);
int				last_med(t_pushswap *var, int flag);
int				ft_swap(int *x, int *mas);
int				ft_swap_b(int *x, int *mas);
void			create_result_b(t_pushswap *var, int size);
void			create_res_a_of_b(t_pushswap *var, int size);
void			create_result_a(t_pushswap *var);
void			create_result_res(t_pushswap *var);
void			create_stack_res_a(t_pushswap *var);
void			free_struct(t_pushswap *var);
int				parser_two(char **argv, int argc, t_pushswap *var);
int				parser(char **argv, int argc, int flag);
int				parser_check_flags(const char *str, int flag);
int				check_duplicate(t_pushswap *var);
int				while_space(const char *str);
int				error(void);
int				check_char_stack(char ch);
void			out_two_mass(t_pushswap *var);
void			sort_res_number(t_pushswap *var);
void			create_stack_index(t_pushswap *var);
int				ft_power2(long long int nb, int notation);
int				ft_atoi_err(const char *str, int *err);

#endif
