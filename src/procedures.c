/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:36:40 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/15 16:15:54 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a
//Do nothing if there is only one or no elements.
void	_sa(t_node **a, bool print)
{
	t_node	*holder;

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
	t_node	*old_first_node;

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
// -- (*a) is the head pointer --
void	_ra(t_node **a, bool print)
{
	t_node	*first_node;

	first_node = *a;
	*a = last_node(*a);
	(*a)->next = first_node;
	(*a) = first_node->next;
	first_node->next = NULL;
	if (print == true)
		write(1, "ra\n", 3);
}

//Shift up all elements of stack b by 1.
//The first element becomes the last one.
// -- (*b) is the head pointer --
void	_rb(t_node **b, bool print)
{
	t_node	*first_node;

	first_node = *b;
	*b = last_node(*b);
	(*b)->next = first_node;
	(*b) = first_node->next;
	first_node->next = NULL;
	if (print == true)
		write(1, "rb\n", 3);
}

//ra and rb at the same time.
void	_rr(t_node **a, t_node **b)
{
	_ra(a, 0);
	_rb(b, 0);
	write(1, "rr\n", 3);
}

//(reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	_rra(t_node **a, bool print)
{
	t_node	*first_node;
	int	i;

	i = 0;
	first_node = (*a);
	while ((*a)->next)
	{
		(*a) = (*a)->next;
		i++;
	}
	(*a)->next = first_node; //mete o ultimo node em cima;
	while (i > 1)
	{
		first_node = first_node->next;
		i--;
	}
	first_node->next = NULL;
	if (print == true)
		write(1, "rra\n", 3);
}

//(reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	_rrb(t_node **b, bool print)
{
	t_node	*first_node;
	int	i;

	i = 0;
	first_node = (*b);
	while ((*b)->next)
	{
		(*b) = (*b)->next;
		i++;
	}
	(*b)->next = first_node; //mete o ultimo node em cima;
	while (i > 1)
	{
		first_node = first_node->next;
		i--;
	}
	first_node->next = NULL;
	if (print == true)
		write(1, "rrb\n", 3);
}

//rra and rrb at the same time.
void	_rrr(t_node **a, t_node **b)
{
	_rra(a, 0);
	_rrb(b, 0);
	write(1, "rrr\n", 3);
}