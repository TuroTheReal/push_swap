/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:44:07 by artberna          #+#    #+#             */
/*   Updated: 2024/07/01 12:10:01 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions de mouvement

static void	rotate(t_pswap **stack)
{
	t_pswap	*first;
	t_pswap	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_findlast(*stack);
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_pswap **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_pswap **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_pswap **a, t_pswap**b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
