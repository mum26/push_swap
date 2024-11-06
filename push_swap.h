/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:10:13 by sishige           #+#    #+#             */
/*   Updated: 2024/11/06 20:04:30 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TER_DIGITS "012"

# define FUNC_SUCCESS 0
# define FUNC_FAILUER 1

# define L 0
# define R 1
# define LR 2

# include "libft/libft.h"

typedef struct s_contents
{
	int				num;
	unsigned int	map;
	char			*ternary;
}				t_contents;

/* push_swap */
void		exec_sort(t_list **stack_a, t_list **stack_b, int argc);
//int		cleaning_up(t_list **stack_a, t_list **stack_b);

/* lst */
int			make_lst(t_list **lst);
void		make_stack_a(t_list **stack_a, int *argc, char *argv[]);
t_list		*make_node(t_list *sentinel, char *argv);
int			fail_init_stack_a(t_list *sentinel, t_list *stack_a);
int			init_stack_a(t_list *stack_a, int argc, char *argv[]);


/* contents */
char		*num_to_ternary(int n, size_t digit);
int			lstiter_num_to_ternary(t_list *lst, int argc);
void		free_contents(void *contents);
t_contents	*make_contents(char *str, t_list *sentinel);

/* util */
int			is_duplicate(int n, t_list *sentinel);
int			is_quoting(char *argv);
int			is_sorted(t_list *sentinel);
char		*parse_sign(char *str, int *sign);
int			safe_atoi(int *n, char *str);

/* arg */
size_t		count_words(char const *str, char c);
int			str_token(char ***dst, char const *str, char c);

/* die */
void		die(char *cause);

/* sort */

/* radix_sort */
void	radix_sort(t_list **stack_a, t_list **stack_b, int argc);
bool	lst_checker(t_list **lst);

/* print */
void		print_lst(char const *str, t_list **lst);
void		print_node(char const *str, t_list **node);
void		print_content(char const *str, t_list *node);

/* COMMAND */
/* swap */
void		swap_content(t_list *a, t_list *b, char *str);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		sa_and_sb(t_list **stack_a, t_list **stack_b);

/* push */
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_b, t_list **stack_a);

/* rotate */
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		ra_and_rb(t_list **stack_a, t_list **stack_b);

/* reverse rotate */
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		rra_and_rrb(t_list **stack_a, t_list **stack_b);

#endif
