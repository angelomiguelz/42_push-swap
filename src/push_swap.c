/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/14 14:35:10 by mzarichn         ###   ########.fr       */
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
}

int main(int ac, char **av)
{
	t_node *a;
	//t_node *b;

	a = _createList(ac, av);
	printf("A: ");
	_pephole(a);
	
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