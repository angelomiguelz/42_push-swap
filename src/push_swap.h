/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:18 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/01 13:52:56 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/src/libft.h"

typedef struct s_stack {
	long	nbr;
	long	index;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack	*_checker(int ac, char **av);

#endif