/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:34:13 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 12:25:32 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_bottom(t_stack **stack_a, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	tail = get_stack_bottom(*stack_a);
	tail->next = new;
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack_values(char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	i = 1;
	nb = 0;
	while (i < countline(argv))
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

t_stack	*fill_stack_values_strs(char **strs)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	i = 0;
	nb = 0;
	while (i < countline_strs(strs))
	{
		nb = ft_atoi(strs[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
