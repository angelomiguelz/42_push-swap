/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:36:40 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/03 21:12:57 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a
//Do nothing if there is only one or no elements.
void	_sa(t_stack **a)
{
	t_stack *hold;

	if (!(*a)->next || !(*a))
		return ;
	hold = (*a)->next;
	(*a)->next = (*a);
	(*a) = hold;	
	write(1, "sa\n", 3);
}

void	_sb(t_stack **a)
{
	write(1, "sb\n", 3);
}

void	_ss(t_stack **a)
{
	write(1, "ss\n", 3);
}

void	_pa(t_stack **a)
{
	write(1, "pa\n", 3);
}

void	_pb(t_stack **a)
{
	write(1, "pb\n", 3);
}

void	_ra(t_stack **a)
{
	write(1, "ra\n", 3);
}

void	_rb(t_stack **a)
{
	write(1, "rb\n", 3);
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 3);
}

void	rrb(t_stack **a)
{
	write(1, "rrb\n", 3);
}

void	_rrr(t_stack **a)
{
	write(1, "rrr\n", 3);
}