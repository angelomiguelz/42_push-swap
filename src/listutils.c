/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:14 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/21 11:45:38 by mzarichn         ###   ########.fr       */
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
	if (!stack) //if theres no list
		return ;
	if (!*stack) //if theres no nodes in list, the givin node will be the first one.
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

t_node	*_stringProcess(char **av)
{
	t_node	*a;
	char	**str;
	int		i;
	int		j;

	a = NULL;
	i = -1;
	str = ft_split(av[1], ' ');
	while (str[++i])
	{
		j = _atoi(str[i]);
		//printf("ATOI: %i\n", j);
		add_node(&a, new_node(j));
	}
	_free(NULL, str);
	return (a);
}

int _checkdup(t_node *a)
{
	t_node *temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (0);
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

bool	_checkSorted(t_node *a)
{
	long int	nbr;

	nbr = a->nbr;
	while (a)
	{
		//printf("number check: %li\n", nbr);
		//printf("number other check: %li\n", a->nbr);
		if (nbr > a->nbr)
			return (false);
		nbr = a->nbr;
		a = a->next;
		//printf("next\n");
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
	if (ac < 2)
		_error();
	if (ac == 2)
	{
		//printf("string process\n");
		a = _stringProcess(av);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			j = _atoi(av[i]);
			add_node(&a, new_node(j));
			i++;
		}
	}
	if (!_checkdup(a))
	{
		printf("CHECK DUP ERROU\n");
		_error();
	}
	_indexStack(&a);
	return (a);
}