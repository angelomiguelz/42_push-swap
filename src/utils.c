/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:06:10 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/28 18:15:52 by mzarichn         ###   ########.fr       */
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

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	arg_is_number(char *s)
{
	int	i;

	i = 0;
	if (is_sign(s[i]) && s[i + 1] != '\0')
		i++;
	while (s[i] && is_digit(s[i]))
		i++;
	if (s[i] != '\0' && !is_digit(s[i]))
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

/* int	_atoi(const char *s)
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
} */