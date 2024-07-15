/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:41:35 by artberna          #+#    #+#             */
/*   Updated: 2024/07/11 10:57:42 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_algo(t_pswap **a, t_pswap **b)
{
	if (!(*a) || !a)
		return ;
	if (find_len(*a) == 2)
		sa(a);
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) <= 5)
		sort_five(a, b);
	else
		grand_sort(a, b);
}
/* void	join_split(int ac, char **av, char *set)
{

} */

static char	*join_arg(int ac, char **av)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	str = NULL;
	while (++i < ac)
	{
		if (str == NULL)
			str = ft_strjoin(av[i], "");
		else
		{
			tmp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(tmp, av[i]);
			free(tmp);
		}
	}
	return (str);
}

static int	check_spaces(int ac, char **av)
{
	char	*just_space;
	int		i;
	int		with_spaces;

	i = 1;
	with_spaces = 1;
	while (i < ac)
	{
		just_space = ft_strtrim(av[i], " ");
		if (ft_strlen(just_space) != 0)
			with_spaces = 0;
		free(just_space);
		i++;
	}
	if (with_spaces)
		return (FALSE);
	return (TRUE);
}

static int	init_stack(int ac, char **av, t_pswap **a)
{
	char	**tab;
	char	*str;

	if (check_spaces(ac, av) == FALSE)
		return (FALSE);
	str = join_arg(ac, av);
	if (!str)
		return (FALSE);
	tab = ft_split(str, ' ');
	if (!tab)
		return (FALSE);
	free(str);
	if (manage_input(tab, a) == FALSE)
	{
		free_list(*a);
		free_malloc(tab);
		return (FALSE);
	}
	return (free_malloc(tab), TRUE);
}

int	main(int ac, char **av)
{
	t_pswap	*a;
	t_pswap	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	else if (ac == 2 && ft_strncmp(av[1], "", 1) == 0)
		return (write(2, "Error\n", 6), 1);
	else if (init_stack(ac, av, &a) == FALSE)
		return (write(2, "Error\n", 6), 1);
	if (stack_sorted(&a) == FALSE)
		all_algo(&a, &b);
	free_list(a);
	return (0);
}
