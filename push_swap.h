/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:10:13 by sishige           #+#    #+#             */
/*   Updated: 2024/10/22 20:28:28 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_TERNARY_MAX_LEN 22
# define TER_DIGITS "012"

# include "libft/libft.h"

typedef struct s_contents
{
	char			*str;
	int				num;
	unsigned long	map;
	char			ternary[INT_TERNARY_MAX_LEN];
}				t_contents;

void	die(char *cause);

#endif
