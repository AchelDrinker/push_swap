/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:24:48 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 13:06:29 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_word
{
	unsigned int	start;
	size_t			len;
}	t_word;

void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
void		do_pushswap(t_stack *stack_a, t_stack *stack_b, int stack_size);
t_stack		*fill_stack_values(char **argv);
t_stack		*fill_stack_values_strs(char **strs);
void		assign_index(t_stack *stack_a, int argc);
int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
int			countline(char **argv);
int			countline_strs(char **strs);
void		*ft_calloc( size_t c);
void		check_input(char **argv);
void		check_input_strs(char **strs);
int			arg_is_number_strs(char *strs);
int			have_duplicates_strs(char **strs);
int			arg_is_zero_strs(char *strs);
int			is_correct_input_strs(char **strs);

#endif
