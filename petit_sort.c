/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:42:32 by artberna          #+#    #+#             */
/*   Updated: 2024/07/03 10:40:06 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions pour Insertion_sort

void	sort_three(t_pswap **a)
{
	int	biggest;

	find_biggest(*a);
	biggest = (*a)->maxvalue;
	if ((*a)->value == biggest)
		ra(a);
	else if ((*a)->next->value == biggest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	push_until_three(t_pswap **a, t_pswap **b)
{
	int			len;
	t_pswap		*last_node;
	t_pswap		*small;

	small = find_smallest(*a);
	len = find_len(*a);
	last_node = ft_findlast(*a);
	while (len > 3)
	{
		if ((*a)->value == small->value)
		{
			pb(b, a);
			small = find_smallest(*a);
			len--;
		}
		else if (last_node->value == (*a)->maxvalue
			|| last_node->value == small->value)
			rra(a);
		else
			ra(a);
	}
}

void	sort_five(t_pswap **a, t_pswap **b)
{
	push_until_three(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
