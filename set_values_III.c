/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_III.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:21:57 by artberna          #+#    #+#             */
/*   Updated: 2024/07/03 11:48:07 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions pour set values de la structure

t_pswap	*send_cheapest(t_pswap *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	values_zero(t_pswap **stack)
{
	(*stack)->len = 0;
	(*stack)->maxvalue = 0;
	(*stack)->above_mediane = 0;
	(*stack)->current_position = 0;
	(*stack)->push_price = 0;
	(*stack)->target_node = 0;
	(*stack)->cheapest = 0;
}

void	init_values(t_pswap **a, t_pswap **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	values_zero(a);
	values_zero(b);
	set_position(*a);
	set_position(*b);
	find_target(*a, *b);
	find_price(*a, *b);
	find_cheapest(*b);
}
