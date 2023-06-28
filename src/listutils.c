/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:14 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/28 17:59:14 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodes_quantity(t_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

// This function returns the last node of the stack.
t_node	*last_node(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// Function to add a new node to the list
void	add_node(t_node **stack, t_node *node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = node;
	else
		(last_node(*stack))->next = node;
}

//Creates a New Node
t_node	*new_node(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		_error();
	new_node->nbr = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

bool	_checkSorted(t_node *a)
{
	long int	nbr;

	nbr = a->nbr;
	while (a)
	{
		if (nbr > a->nbr)
			return (false);
		nbr = a->nbr;
		a = a->next;
	}
	return (true);
}

t_node	*get_next_min(t_node *stack)
{
	t_node	*head;
	t_node	*min;
	bool	starter;

	min = NULL;
	head = stack;
	starter = false;
	while (head)
	{
		if ((head->index == -1) && (!starter || head->nbr < min->nbr))
		{
			starter = true;
			min = head;
		}
		head = head->next;
	}
	return (min);
}

void	_indexStack(t_node **stack)
{
	t_node	*head;
	long		index;

	index = 0;
	head = get_next_min(*stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(*stack);
	}
}

t_node	*_createList(int ac, char **av)
{
	t_node *a;
	int	i;
	int	j;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		j = ft_atoi(av[i]);
		add_node(&a, new_node(j));
		i++;
	}
	_indexStack(&a);
	return (a);
}