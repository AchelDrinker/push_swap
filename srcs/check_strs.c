/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:52:18 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 13:06:40 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	arg_is_number_strs(char *strs)
{
	int	i;

	i = 0;
	if (is_sign(strs[i]) && strs[i + 1] != '\0')
		i++;
	while (strs[i] && is_digit(strs[i]))
		i++;
	if (strs[i] != '\0' && !is_digit(strs[i]))
		return (0);
	return (1);
}

int	have_duplicates_strs(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[j])
		{
			if (j != i && nbstr_cmp(strs[i], strs[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_is_zero_strs(char *strs)
{
	int	i;

	i = 0;
	if (is_sign(strs[i]))
		i++;
	while (strs[i] && strs[i] == '0')
		i++;
	if (strs[i] != '\0')
		return (0);
	return (1);
}

void	check_input_strs(char **strs)
{
	if (!is_correct_input_strs(strs))
		exit_error(NULL, NULL);
}
