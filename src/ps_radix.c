/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:32:22 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 13:32:18 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b, int total_ints, int bit)
{
	int	i;

	i = 0;
	if (is_sort(stack_a) || bit >= 16)
		return ;
	while (i++ < total_ints)
	{
		if ((tip(stack_a)->number >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	while (left_in_stack(stack_a) < total_ints)
		pa(stack_a, stack_b);
	radix(stack_a, stack_b, total_ints, ++bit);
}
