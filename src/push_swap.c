/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/03 21:13:38 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO:
// - Put Procedures on H
// - Create function to check if sorted
// - Sort if 2 args
// - Sort if 3 args


int main(int ac, char **av)
{
	t_stack *a;

	a = _checker(ac, av);
	if (!a)
		printf("TUA MAE\n\n");
	while (a)
	{
		printf("NUMBERS: %li\n", a->nbr);
		a = a->next;
	}
	return (1);
} 
