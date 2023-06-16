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

void	_sort(t_node **a, t_node **b)
{
	_pb(a, b);
	_pb(a, b);
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	a = _createList(ac, av);
	printf("First Stack A:\n");
	_pephole(a);
	if (!_checkSorted(a))
	{
		if (nodes_quantity(a) == 2)
			_sa(&a, 1);
		else
			_sort(&a, &b);
	}
	printf("\nAfter Stack A:\n");
	_pephole(a);
	printf("After Stack B:\n");
	_pephole(b);
	return (1);
} 

	/* b = _createList(ac, av);
	b->nbr = 4;
	printf("A: ");
	_pephole(a);
	if (!a)
		printf("TUA MAE\n\n");
	_pa(&a, &b);
	_pa(&a, &b);
	printf("\nA: ");
	_pephole(a);
	printf("\n");
	a->nbr = 420;
	_pb(&a, &b);
	printf("\nB: ");
	_pephole(b);
	printf("\n");
	printf("\nA: ");
	_pephole(a); */