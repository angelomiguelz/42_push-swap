/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:36:40 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/14 14:16:44 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a
//Do nothing if there is only one or no elements.
void	_sa(t_node **a, bool print)
{
	t_node *holder;

	if (!(*a) || !(*a)->next)
		return ;
	holder = (*a);
	(*a) = (*a)->next;
	holder->next = (*a)->next;
	(*a)->next = holder;
	if (print == true)
		write(1, "sa\n", 3);
}
//Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	_sb(t_node **b, bool print)
{
	t_node	*holder;

	if (!(*b)->next || !(*b))
		return ;
	holder = (*b);
	(*b) = (*b)->next;
	holder->next = (*b)->next;
	(*b)->next = holder;
	if (print == true)
		write(1, "sb\n", 3);
}

//sa and sb at the same time.
void	_ss(t_node **a, t_node **b)
{
	_sa(a, 0);
	_sb(b, 0);
	write(1, "ss\n", 3);
}

//Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void	_pa(t_node **a, t_node **b)
{
	t_node *old_first_node;

	if (!(*b))
		return ;
	old_first_node = (*a);
	(*a) = (*b);
	(*b) = (*b)->next;
	(*a)->next = old_first_node;
	write(1, "pa\n", 3);
}

//Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void	_pb(t_node **a, t_node **b)
{
	t_node	*old_first_node;

	if (!(*a))
		return ;
	old_first_node = (*b);
	(*b) = (*a);
	(*a) = (*a)->next;
	(*b)->next = old_first_node;
	write(1, "pb\n", 3);
}

//Shift up all elements of stack a by 1.
//The first element becomes the last one.
void	_ra(t_node **a, bool print)
{
	t_node	*first_node;

	first_node = *a;
	*a = last_element(*a);
	(*a)->next = first_node;
	if (print == true)
		write(1, "ra\n", 3);
}

/* void	_rb(t_stack **a)
{
	write(1, "rb\n", 3);
} */

/* void	rra(t_stack **a)
{
	write(1, "rra\n", 3);
} */

/* void	rrb(t_stack **a)
{
	write(1, "rrb\n", 3);
} */

/* void	_rrr(t_stack **a)
{
	write(1, "rrr\n", 3);
} */