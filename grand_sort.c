/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:31:49 by artberna          #+#    #+#             */
/*   Updated: 2024/07/03 11:06:42 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions pour Merge_sort

static void	end_rotation(t_pswap **stack, t_pswap *node, char name)
{
	while (*stack != node)
	{
		if (name == 'a')
		{
			if (node->above_mediane == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (node->above_mediane == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_values(t_pswap **a, t_pswap **b)
{
	t_pswap	*the_node;

	the_node = send_cheapest(*b);
	if (the_node->above_mediane == 1
		&& the_node->target_node->above_mediane == 1)
		double_rotate(a, b, the_node);
	else if (the_node->above_mediane == 0
		&& the_node->target_node->above_mediane == 0)
		double_r_rotate(a, b, the_node);
	end_rotation(b, the_node, 'b');
	end_rotation(a, the_node->target_node, 'a');
	pa(a, b);
}

void	grand_sort(t_pswap **a, t_pswap **b)
{
	int		len;
	t_pswap	*small;

	len = find_len(*a);
	while (len-- > 3)
		pb(b, a);
	sort_three(a);
	while (*b)
	{
		init_values(a, b);
		move_values(a, b);
	}
	set_position(*a);
	small = find_smallest(*a);
	if (small->above_mediane == 1)
		while (*a != small)
			ra(a);
	else
		while (*a != small)
			rra(a);
}
