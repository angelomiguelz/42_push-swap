/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/28 18:02:03 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (ac > 2)
	{
		_checkArgs(ac, av);
		a = _createList(ac, av);
		if (!_checkSorted(a))
		{
			if (nodes_quantity(a) <= 5)
				_sort2to5(&a, &b);
			else
				_radixSort(&a, &b);
		}
		_freeList(&a);
	}
	return (1);
}