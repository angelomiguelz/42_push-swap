/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:32:14 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/04 17:48:24 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_error()
{
	write (2, "Error\n", 6);
	exit(1);
}

// This function returns the last element of the stack.
t_stack	*last_element(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Function to add a new node to the stack from back side
void	node_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(last_element(*stack))->next = stack_new;
}

int	_atoi(const char *s)
{
	int				sign;
	long long int	nbr;

	nbr = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\f'
		|| *s == '\v' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
		{
			sign = -1;
			s++;
		}
		else
			s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			_error();
		nbr = nbr * 10 + (*s - 48);
		s++;
	}
	if ((sign * nbr) > 2147483647 || (sign * nbr) < -2147483648)
		_error();
	return (sign * nbr);
}

void	_free(char *string, char **matrix)
{
	int	i;

	if (string != NULL)
	{
		free(string);
	}
	if (matrix != NULL)
	{
		i = -1;
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
}

//Creates a New Node
t_stack	*new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

t_stack	*_stringProcess(char **av)
{
	t_stack	*a;
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
		node_add_back(&a, new_node(j));
	}
	_free(NULL, str);
	return (a);
}

int _checkdup(t_stack *a)
{
	t_stack *temp;

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



t_stack	*_createList(int ac, char **av)
{
	t_stack *a;
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
			node_add_back(&a, new_node(j));
			i++;
		}
	}
	if (!_checkdup(a))
	{
		printf("CHECK DUP ERROU\n");
		_error();
	}
	return (a);
}