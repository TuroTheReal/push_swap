/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:27:02 by artberna          #+#    #+#             */
/*   Updated: 2024/07/15 10:12:51 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions qui gerent l'input

static int	check_double(int value, t_pswap *a)
{
	while (a != NULL)
	{
		if (value == a->value)
			return (FALSE);
		a = a->next;
	}
	return (TRUE);
}

static int	check_input(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if ((s[i][0] == '-' && ft_isdigit(s[i][1]) == 1) || (s[i][0] == '+'
		&& ft_isdigit(s[i][1]) == 1))
			j++;
		while (s[i][j])
		{
			if (ft_isdigit(s[i][j]))
				j++;
			else
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	manage_input(char **s, t_pswap **a)
{
	int			i;
	long		value;

	i = 0;
	if (check_input(s) == FALSE)
		return (FALSE);
	while (s[i])
	{
		value = ft_atol(s[i]);
		if (value == OVERFLOW)
			return (FALSE);
		if (value > INT_MAX || value < INT_MIN)
			return (FALSE);
		else if (check_double(value, *a) == FALSE)
			return (FALSE);
		else
			put_node_at_end(a, value);
		i++;
	}
	return (TRUE);
}
