/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:09 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 13:06:45 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	countline_strs(char **strs)
{
	int		i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

void	do_pushswap(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	is_correct_input_strs(char **strs)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 0;
	while (strs[i])
	{
		if (!arg_is_number_strs(strs[i]))
			return (0);
		nb_zeros += arg_is_zero_strs(strs[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates_strs(strs))
		return (0);
	return (1);
}

void	check_input(char **argv)
{
	if (!is_correct_input(argv))
		exit_error(NULL, NULL);
}
