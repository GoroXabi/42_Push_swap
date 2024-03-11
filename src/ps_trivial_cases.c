/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_trivial_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:16:01 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 13:26:42 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_stack **stack_a, int total_ints)
{
	if (tip(stack_a)->number == total_ints - 2 && !is_sort(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (tip(stack_a)->number == total_ints - 1)
	{
		if (tip(stack_a)->next->number == total_ints - 2)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else if (tip(stack_a)->number == total_ints)
	{
		if (tip(stack_a)->next->number == total_ints - 2)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	case_5(t_stack **stack_a, t_stack **stack_b, int total_ints)
{
	while (left_in_stack(stack_a) > 3)
	{
		if (tip(stack_a)->number <= 2)
			pb(stack_a, stack_b);
		else if (base(stack_a)->number <= 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	case_3(stack_a, total_ints);
	if (tip(stack_b)->number == 1)
		sb(stack_b);
	if (total_ints == 5)
		pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
