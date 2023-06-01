/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/01 14:38:36 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
