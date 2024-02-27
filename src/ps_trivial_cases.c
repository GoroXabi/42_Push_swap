/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_trivial_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:16:01 by xortega           #+#    #+#             */
/*   Updated: 2024/02/27 13:08:12 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	current_stack_size(t_stack **stack)
{
	int 	i;
	t_stack	*current;
	
	current = *stack;
	i = 0;
	while(current->next)
	{
		if (current->number > 0)
			i++;
		current = current->next;
	}
	return (i);
}

void	case_3(t_stack **stack_a)
{
	t_stack	*a;

	a = *stack_a;
	if (a->number == 1 && !is_sort(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (a->number == 2)
	{
		if (a->next->number == 1)
			sa(stack_a);
		else
			rra(stack_a);
	}
	if (a->number == 3)
	{
		if (a->next->number == 1)
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
/*	t_stack	*a; 
	t_stack	*b;
	int		pivot;
*/

	total_ints = 0;
	pb(stack_a, stack_b);
	print_list(stack_a, stack_b, total_ints);
//	refesh_index(stack_a);
//	refesh_index(stack_b);
/*	a = *stack_a;
	b = *stack_b;
	pivot = total_ints / 2;
	
	while (!is_sort(stack_a))
	{
		if (current_stack_size(stack_a) > pivot)
		{	
			if (a->number > pivot)
				ra(stack_a);
			if (a->number < pivot && a->number != 0)
				pb(stack_a, stack_b);
			if (a->number == pivot)
				sa(stack_a);
		}
		else
			return ;
	}*/
}
