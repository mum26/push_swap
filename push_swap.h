/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:10:13 by sishige           #+#    #+#             */
/*   Updated: 2024/10/29 17:08:56 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_TERNARY_MAX_LEN 22
# define TER_DIGITS "012"

# define FUNC_SUCCESS 0
# define FUNC_FAILUER 1

# include "libft/libft.h"

typedef struct s_contents
{
	char			*str;
	int				num;
	unsigned int	map;
	char			ternary[INT_TERNARY_MAX_LEN];
}				t_contents;

/* push_swap */
//t_list			*make_stacks(t_list **stack_a, int argc, char *argv[]);
//int				exec_sort(t_list **stack_a, t_list **stack_b);
//int				cleaning_up(t_list **stack_a, t_list **stack_b);

/* lst */
int				make_lst(t_list **lst);
void			make_stack_a(t_list **stack_a, int argc, char *argv[]);
t_list			*make_node(t_list *sentinel, char *argv);
int				fail_init_stack_a(t_list *sentinel, t_list *stack_a);
int				init_stack_a(t_list *stack_a, int argc, char *argv[]);
//void			init_stacks(t_list **stack_a, t_list **stack_b, int argc, char *argv[]);

int	is_split(char *argv);

/* contents */
int				lstiter_num_to_ternary(t_list *lst, int offset);
void			free_contents(void *contents);
t_contents		*make_contents(char *str, t_list *sentinel);

/* util */
unsigned int	mapping(int n, int offset);
char			*ulong_to_ternary(char *ternary, unsigned long ul);
char			*parse_sign(char *str, int *sign);
int				safe_atoi(int *n, char *str);
void			set_min(int num, unsigned int *min);

/* arg */
size_t			count_words(char const *str, char c);
int				str_token(char ***dst, char const *str, char c);

/* die */
void	die(char *cause);

/* print */
void	print_lst(char const *str, t_list *lst);
void	print_content(char const *str, t_list *lst);
#endif
