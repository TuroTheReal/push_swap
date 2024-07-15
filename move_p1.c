/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:02:03 by artberna          #+#    #+#             */
/*   Updated: 2024/07/01 12:10:14 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions de mouvement

static void	swap(t_pswap **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	if ((*stack)->next)
		(*stack)->next->prev = *stack;
	(*stack)->prev->next = *stack;
	(*stack)->prev->prev = NULL;
	*stack = (*stack)->prev;
}

void	sa(t_pswap **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_pswap **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_pswap **a, t_pswap **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
