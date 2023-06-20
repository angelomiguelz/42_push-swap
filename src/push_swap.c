/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/16 15:41:54 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://github.dev/42YerevanProjects/push_swap/tree/master/resources
//TODO:
// - do rotates
// - Sort if 3 args

void	_pephole(t_node *a)
{
	while (a)
	{
		printf("NUMBERS: %li\n", (a)->nbr);
		(a) = (a)->next;
	}
	printf("\n");
}

t_node	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_node **stack)
{
	t_node	head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	a = _createList(ac, av);

	index_stack(&a);

	printf("First Stack A:\n");
	_pephole(a);

	if (!_checkSorted(a))
	{
		if (nodes_quantity(a) <= 5 && nodes_quantity(a) != 0 && nodes_quantity(a) != 1)
			simple_sort(&a, &b);
		else
			_sort(&a, &b);
	}

	printf("\nAfter Stack A:\n");
	_pephole(a);
	printf("After Stack B:\n");
	_pephole(b);

	return (1);
}