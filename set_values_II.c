/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_II.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:51:13 by artberna          #+#    #+#             */
/*   Updated: 2024/07/09 14:54:22 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions pour set values de la structure

void	find_target(t_pswap *a, t_pswap *b)
{
	t_pswap	*stack_a;
	t_pswap	*target;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->value > b->value
				&& stack_a->value < best_index)
			{
				best_index = stack_a->value;
				target = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	find_price(t_pswap *a, t_pswap *b)
{
	int	len_a;
	int	len_b;

	len_a = find_len(a);
	len_b = find_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (b->above_mediane == 0)
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_mediane == 1)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	find_cheapest(t_pswap *stack)
{
	long	cheapest;
	t_pswap	*best_node;

	if (!stack)
		return ;
	best_node = NULL;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < cheapest)
		{
			cheapest = stack->push_price;
			best_node = stack;
		}
		stack = stack->next;
	}
	best_node->cheapest = 1;
}

/* void	find_mediane(t_pswap **stack)
{
	int		i;
	t_pswap	*tmp;
	t_pswap	*copy;
	int		middlelen;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	copy = dup_list(tmp);
	if (!copy)
		return ;
	sort_stack(&copy);
	tmp = copy;
	middlelen = (*stack)->middlelen;
	i = 0;
	while (i < middlelen && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp)
		(*stack)->mediane = tmp->value;
	free_list(copy);
}

void	find_mediane_position(t_pswap **stack)
{
	t_pswap	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->value < (*stack)->mediane)
			tmp->above_mediane = FALSE;
		else
			tmp->above_mediane = TRUE;
		tmp = tmp->next;
	}
} */
