/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:24:08 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 13:01:22 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	contains_space(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**strs;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	if (contains_space(argv[1]))
	{
		strs = ft_split(argv[1], ' ');
		check_input_strs(strs);
		stack_a = fill_stack_values_strs(strs);
		stack_size = get_stack_size(stack_a);
		free(strs);
	}
	else
	{
		stack_a = fill_stack_values(argv);
		stack_size = get_stack_size(stack_a);
		check_input(argv);
	}
	do_pushswap(stack_a, stack_b, stack_size);
	return (0);
}
