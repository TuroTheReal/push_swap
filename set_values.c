/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:16:51 by artberna          #+#    #+#             */
/*   Updated: 2024/07/08 10:39:10 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions pour set values de la structure

int	find_len(t_pswap *stack)
{
	int		i;
	t_pswap	*tmp;

	tmp = stack;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	stack->len = i;
	return (i);
}

void	set_position(t_pswap *stack)
{
	int		i;
	int		middle;

	if (!stack)
		return ;
	middle = find_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->current_position = i;
		if (i <= middle)
			stack->above_mediane = 1;
		else
			stack->above_mediane = 0;
		stack = stack->next;
		i++;
	}
}

t_pswap	*find_smallest(t_pswap *stack)
{
	t_pswap	*s_node;
	long	s_value;

	if (!stack)
		return (NULL);
	s_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < s_value)
		{
			s_value = stack->value;
			s_node = stack;
		}
		stack = stack->next;
	}
	return (s_node);
}

t_pswap	*find_biggest(t_pswap *stack)
{
	t_pswap	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	stack->maxvalue = tmp->value;
	while (tmp)
	{
		if (tmp->value > stack->maxvalue)
			stack->maxvalue = tmp->value;
		tmp = tmp->next;
	}
	return (tmp);
}
