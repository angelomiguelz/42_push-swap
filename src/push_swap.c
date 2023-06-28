/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/28 14:49:47 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://github.dev/42YerevanProjects/push_swap/tree/master/resources
//
//TODO:
// - Sort 3
// - Simplify Get next min;

void	_pephole(t_node *a)
{
	while (a)
	{
		printf("NUMBERS: %li\n", (a)->nbr);
		printf("INDEX: %li\n", (a)->index);
		
		(a) = (a)->next;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	a = _createList(ac, av);

/* 	printf("First Stack A:\n");
	_pephole(a);
 */
	if (!_checkSorted(a))
	{
		if (nodes_quantity(a) <= 5)
			_sort2to5(&a, &b);
		else
			_radixSort(&a, &b);
	}
/* 
	printf("\nAfter Stack A:\n");
	_pephole(a);
	printf("After Stack B:\n");
	_pephole(b); */

	return (1);
}