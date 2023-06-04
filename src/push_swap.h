/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:18 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/04 17:54:14 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack {
	long	nbr;
	long	index;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack	*_createList(int ac, char **av);
void	_sa(t_stack **a);

#endif