/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:18 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/28 17:59:30 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_node {
	long	nbr;
	long	index;
	struct s_node *next;
} t_node;

// lists
t_node	*_createList(int ac, char **av);
bool	_checkSorted(t_node *a);
t_node	*last_node(t_node *list);
int		nodes_quantity(t_node *a);
void	_sort2to5(t_node **a, t_node **b);
void	_radixSort(t_node **a, t_node **b);

// procedures
void	_sa(t_node **a, bool print);
void	_sb(t_node **b, bool print);
void	_ss(t_node **a, t_node **b);
void	_pa(t_node **a, t_node **b);
void	_pb(t_node **a, t_node **b);
void	_ra(t_node **a, bool print);
void	_rb(t_node **b, bool print);
void	_rr(t_node **a, t_node	**b);
void	_rra(t_node **a, bool print);
void	_rrb(t_node **b, bool print);
void	_rrr(t_node **a, t_node **b);


// utils
void	_error();
void	_freeList(t_node **a);
void	_free(char *string, char **matrix);
void	_checkArgs(int ac, char **av);

#endif