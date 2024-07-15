/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:10:03 by artberna          #+#    #+#             */
/*   Updated: 2024/07/03 11:53:16 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonctions pour la liste doublement chainees

t_pswap	*ft_findlast(t_pswap *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	free_list(t_pswap *a)
{
	t_pswap	*tmp;

	if (!a)
		return ;
	while (a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

t_pswap	*create_node(int value)
{
	t_pswap	*new_elem;

	new_elem = ft_calloc(sizeof(t_pswap), 1);
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void	put_node_at_end(t_pswap **a, int value)
{
	t_pswap	*new_elem;
	t_pswap	*tmp;

	new_elem = create_node(value);
	if (!new_elem)
		return ;
	if (!*a)
	{
		*a = new_elem;
		return ;
	}
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_elem;
	new_elem->prev = tmp;
}

/* void	print_list(t_pswap *a)
{
	int	i;

	i = 1;
	while (a != NULL)
	{
		ft_printf("Value Node %d is %d\n", i, a->value);
		a = a->next;
		i++;
	}
} */
