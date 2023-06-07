/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:06:10 by mzarichn          #+#    #+#             */
/*   Updated: 2023/06/06 20:49:21 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_error()
{
	write (2, "Error\n", 6);
	exit(1);
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