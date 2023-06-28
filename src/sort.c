/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:05:36 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/28 14:49:27 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node *stack, int stopper)
{
	t_node	*head;
	int		min;

	head = stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != stopper)
			min = head->index;
	}
	return (min);
}

int	get_distance(t_node *head, int index)
{
	int		distance;

	distance = 0;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	_sort3(t_node **a)
{
	t_node	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(*a, -1);
	next_min = get_min(*a, min);
	if (head->index == min && head->next->index != next_min)
	{
		_ra(a, 1);
		_sa(a, 1);
		_rra(a, 1);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			_sa(a, 1);
		else
			_rra(a, 1);
	}
	else
	{
		if (head->next->index == min)
			_ra(a, 1);
		else
		{
			_sa(a, 1);
			_rra(a, 1);
		}
	}
}

void	_sort4(t_node **a, t_node **b)
{
	int	distance;

/* 	if (_checkSorted(*a))
		return ; */
	distance = get_distance(*a, get_min(*a, -1));
	if (distance == 1)
		_ra(a, 1);
	else if (distance == 2)
	{
		_ra(a, 1);
		_ra(a, 1);
	}
	else if (distance == 3)
		_rra(a, 1);
	if (_checkSorted(*a))
		return ;
	_pb(a, b);
	_sort3(a);
	_pa(a, b);
}

void	_sort5(t_node **a, t_node **b)
{
	int	distance;

	distance = get_distance(*a, get_min(*a, -1));
	if (distance == 1)
		_ra(a, 1);
	else if (distance == 2)
	{
		_ra(a, 1);
		_ra(a, 1);
	}
	else if (distance == 3)
	{
		_rra(a, 1);
		_rra(a, 1);
	}
	else if (distance == 4)
		_rra(a, 1);
	if (_checkSorted(*a))
		return ;
	_pb(a, b);
	_sort4(a, b);
	_pa(a, b);
}


void	_sort2to5(t_node **a, t_node **b)
{
	int	size;
	size = nodes_quantity(*a);
	if (size == 2)
		_sa(a, 1);
	else if (size == 3)
		_sort3(a);
	else if (size == 4)
		_sort4(a, b);
	else if (size == 5)
		_sort5(a, b);
}

//gets the max index number and sees 
//the quantity of bits it will need to work with.
int	_maxBits(t_node *head)
{
	int		max;
	int		max_bits;

	max = head->index;
	max_bits = -1;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while (max >> ++max_bits)
		;
	return (max_bits);
}

void	_radixSort(t_node **a, t_node **b)
{
	t_node	*head_a;
	int		i;
	int		size;
	int		max_bits;

	head_a = *a;
	max_bits = _maxBits(*a);
	i = -1;
	while (++i < max_bits)
	{
		size = nodes_quantity(*a);
		while (size--)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				_ra(a, 1);
			else
				_pb(a, b);
		}
		while (nodes_quantity(*b))
			_pa(a, b);
	}
}
