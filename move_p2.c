/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:02:24 by artberna          #+#    #+#             */
/*   Updated: 2024/07/01 12:10:08 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions de mouvement

static void	push(t_pswap **dest, t_pswap **src)
{
	t_pswap	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if ((*src))
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	tmp->prev = NULL;
}

void	pa(t_pswap **a, t_pswap **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_pswap **b, t_pswap **a)
{
	push(b, a);
	ft_printf("pb\n");
}
