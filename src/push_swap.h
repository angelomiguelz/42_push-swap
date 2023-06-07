/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:18 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/07 15:45:43 by mzarichn         ###   ########.fr       */
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
// procedures
void	_sa(t_node **a, bool print);
void	_sb(t_node **b, bool print);
void	_ss(t_node **a, t_node **b);
void	_pa(t_node **a, t_node **b);
// utils
int	_atoi(const char *s);
void	_error();
void	_free(char *string, char **matrix);


#endif