/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:42:25 by artberna          #+#    #+#             */
/*   Updated: 2024/07/15 16:40:56 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_library/my_library.h"

typedef struct s_pswap
{
	struct s_pswap	*prev;
	struct s_pswap	*next;
	struct s_pswap	*target_node;
	int				value;
	int				maxvalue;
	int				len;
	int				above_mediane;
	int				current_position;
	int				push_price;
	int				cheapest;
}					t_pswap;

typedef enum e_error
{
	TRUE = 1,
	FALSE = 0,
	OVERFLOW = -111111111111111,
}	t_error;

// Fonctions input
int		manage_input(char **s, t_pswap **a);

// Fonctions utilitaires
void	**free_malloc(char **s);
long	ft_atol(const char *s);
int		stack_sorted(t_pswap **stack);

// Fonctions structures
t_pswap	*create_node(int value);
void	put_node_at_end(t_pswap **a, int value);
void	free_list(t_pswap *a);
t_pswap	*ft_findlast(t_pswap *stack);

// Fonctions tri
void	sa(t_pswap **a);
void	sb(t_pswap **a);
void	ss(t_pswap **a, t_pswap **b);
void	pa(t_pswap **a, t_pswap **b);
void	pb(t_pswap **b, t_pswap **a);
void	ra(t_pswap **a);
void	rb(t_pswap **b);
void	rr(t_pswap **a, t_pswap **b);
void	rra(t_pswap **a);
void	rrb(t_pswap **b);
void	rrr(t_pswap **a, t_pswap **b);
void	double_rotate(t_pswap **a, t_pswap **b, t_pswap *the_node);
void	double_r_rotate(t_pswap **a, t_pswap **b, t_pswap *the_node);

// Fonction algo
void	sort_three(t_pswap **a);
void	sort_five(t_pswap **a, t_pswap **b);
void	grand_sort(t_pswap **a, t_pswap **b);

// Fonction set values structure
void	init_values(t_pswap **a, t_pswap **b);
void	values_zero(t_pswap **stack);
t_pswap	*find_biggest(t_pswap *stack);
t_pswap	*find_smallest(t_pswap *stack);
int		find_len(t_pswap *stack);
void	set_position(t_pswap *stack);
void	find_price(t_pswap *a, t_pswap *b);
void	find_cheapest(t_pswap *stack);
t_pswap	*send_cheapest(t_pswap *stack);
void	find_target(t_pswap *a, t_pswap *b);

#endif