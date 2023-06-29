/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:06:10 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/29 12:41:39 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_error()
{
	write (1, "Error\n", 6);
	exit(1);
}

void	_freeList(t_node **a)
{
	t_node	*tmp;

	if (!a || !(*a))
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	_free(char *string, char **matrix)
{
	int	i;

	if (string != NULL)
		free(string);
	if (matrix != NULL)
	{
		i = -1;
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
}

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	_checkDuplicates(int number, char **args, int pos)
{
	while (args[++pos])
	{
		if (ft_atoi(args[pos]) == number)
			return (1);
	}
	return (0);
}

int	arg_is_number(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1] != '\0')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (s[i] != '\0' && (s[i] < '0' && s[i] > '9'))
		return (0);
	return (1);
}

void	_checkArgs(int ac, char **av)
{
	int i;
	long number;
	bool error;
	
	error = false;
	i = 0;
	number = -1;
	while (++i < ac)
	{
		if (!arg_is_number(av[i]))
			error = true;
		number = ft_atoi(av[i]);
		if (ft_isdigit(number))
			error = true;
		if(_checkDuplicates(number, av, i))
			error = true;
		if (number < -2147483648 || number > 2147483647)
			error = true;
		if (error == true)
			_error();
	}
}
