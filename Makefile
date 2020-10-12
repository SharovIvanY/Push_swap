# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 15:39:39 by amace-ty          #+#    #+#              #
#    Updated: 2019/10/20 14:53:03 by amace-ty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIBFT =		ft_atoi.c\
				ft_bzero.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				get_next_line.c
SRC_PRINTF =	analise.c\
				analise_char.c\
				analise_float_and_l.c\
				analise_float_upl.c\
				analise_h_hh_unsigned_integer.c\
				analise_h_hh_upx.c\
				analise_h_hh_x.c\
				analise_h_o.c\
				analise_hh_o.c\
				analise_j.c\
				analise_l_ll_u.c\
				analise_l_ll_upx.c\
				analise_l_ll_x.c\
				analise_l_o.c\
				analise_ll_o.c\
				analise_pointer.c\
				analise_procent.c\
				analise_str.c\
				analise_three.c\
				analise_two.c\
				analise_u.c\
				analise_upx.c\
				analise_x.c\
				analyse_integer.c\
				analyse_o.c\
				check_flags_di.c\
				check_flags_upxxuo.c\
				check_flags_upxxuo2.c\
				create_struct.c\
				float_help.c\
				float_help_part_two.c\
				float_help_part_two_upl.c\
				float_help_upl.c\
				ft_litoa.c\
				ft_llitoa.c\
				ft_printf.c\
				ft_printf_three.c\
				ft_printf_two.c\
				ft_width_for_int.c\
				new.c\
				print_null_i.c\
				print_pointer.c\
				print_string.c
SRC =			base_one.c\
				base_two.c\
				base_three.c\
				function_checking.c\
				function_create.c\
				function_for_algoritm.c\
				function_for_algoritm_two.c\
				function_free.c\
				function_initialization.c\
				function_swap.c\
				help.c\
				other_push_swap.c\
				parsers.c\
				sort_and_print.c
INCLUDE = 		-Ilibftprintf\
			   	-Ilibftprintf/libft
SRC_CH =		checker.c
SRC_PU =		push_swap.c
HEAD =			push_swap.h
DIR_LIBFT = 	libftprintf/libft/
DIR_PRINTF =	libftprintf/
LIBFT_PRINTF =	libftprintf.a
PUSH_SWAP =		push_swap
CHECKER =		checker
FLAGS =			-Wall -Wextra -Werror
CC =			gcc
PSRC_LIBFT = $(addprefix $(DIR_LIBFT), $(SRC_LIBFT))
PSRC_PRINTF = $(addprefix $(DIR_PRINTF), $(SRC_PRINTF))
OBJ_PRINTF = $(PSRC_PRINTF:.c=.o) $(PSRC_LIBFT:.c=.o)
OBJ_CH = $(SRC_CH:.c=.o) $(SRC:.c=.o)
OBJ_PU = $(SRC_PU:.c=.o) $(SRC:.c=.o)

all: $(PUSH_SWAP) $(CHECKER)

$(CHECKER): $(LIBFT_PRINTF) $(OBJ_CH) $(HEAD)
	@$(CC) $(FLAGS) $(OBJ_CH) $(LIBFT_PRINTF) $(INCLUDE) -o $(CHECKER)
	@echo "checker compiled"

$(PUSH_SWAP): $(LIBFT_PRINTF) $(OBJ_PU) $(HEAD)
	@$(CC) $(FLAGS) $(OBJ_PU) $(LIBFT_PRINTF) $(INCLUDE) -o $(PUSH_SWAP)
	@echo "push_swap compiled"

$(LIBFT_PRINTF): $(OBJ_PRINTF)
	@ar rc $(LIBFT_PRINTF) $(OBJ_PRINTF)
	@ranlib $(LIBFT_PRINTF)
	@echo "libftprintf.a compiled"

.c.o:
	$(CC) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ_PRINTF)
	@/bin/rm -f $(OBJ_SRC)
	@/bin/rm -f $(OBJ_PU)
	@/bin/rm -f $(OBJ_CH)

fclean:
	@/bin/rm -f $(LIBFT_PRINTF)
	@/bin/rm -f $(PUSH_SWAP)
	@/bin/rm -f $(CHECKER)

re: fclean all

.PHONY: clean fclean all re lib push_swap checker
