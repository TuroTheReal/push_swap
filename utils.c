/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:42:36 by artberna          #+#    #+#             */
/*   Updated: 2024/07/15 10:12:46 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions utilitaires

void	**free_malloc(char **s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

long	ft_atol(const char *s)
{
	long	parity;
	long	number;

	parity = 1;
	number = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			parity = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		number *= 10;
		number += *s - 48;
		if (number > INT_MAX || number < INT_MIN)
			return (OVERFLOW);
		s++;
	}
	return (number * parity);
}

int	stack_sorted(t_pswap **stack)
{
	t_pswap	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
