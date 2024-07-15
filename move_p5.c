/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:08:44 by artberna          #+#    #+#             */
/*   Updated: 2024/07/03 10:09:38 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions de mouvement

void	double_rotate(t_pswap **a, t_pswap **b, t_pswap *the_node)
{
	while (*a != the_node->target_node
		&& *b != the_node)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

void	double_r_rotate(t_pswap **a, t_pswap **b, t_pswap *the_node)
{
	while (*a != the_node->target_node
		&& *b != the_node)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}
