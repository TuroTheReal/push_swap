/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:23:24 by artberna          #+#    #+#             */
/*   Updated: 2024/07/08 10:29:40 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions de mouvement

void	reverse_rotate(t_pswap **stack)
{
	t_pswap	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_findlast(*stack);
	if (last->prev)
			last->prev->next = NULL;
	last->next = (*stack);
	if (*stack)
			(*stack)->prev = last;
	*stack = last;
	last->prev = NULL;
}

void	rra(t_pswap **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_pswap **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_pswap **a, t_pswap**b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
