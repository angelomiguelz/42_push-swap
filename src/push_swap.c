/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/04 17:51:22 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO:
// - Put Procedures on H
// - Create function to check if sorted
// - Sort if 2 args
// - Sort if 3 args

void	_pephole(t_stack *a)
{
	while (a)
	{
		printf("NUMBERS: %li\n", (a)->nbr);
		(a) = (a)->next;
	}
}


int main(int ac, char **av)
{
	t_stack *a;

	a = _createList(ac, av);
	_pephole(a);
	if (!a)
		printf("TUA MAE\n\n");
	_sa(&a);
	_pephole(a);
	return (1);
} 
