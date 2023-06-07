/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/07 15:47:12 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO:
// - Put Procedures on H
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
	t_node *b;

	a = _createList(ac, av);
	b = _createList(ac, av);
	b->nbr = 4;
	_pephole(a);
	_pephole(b);
	if (!a)
		printf("TUA MAE\n\n");
	_pa(&a, &b);
	_pephole(a);
	return (1);
} 
