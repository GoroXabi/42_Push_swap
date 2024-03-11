/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:14 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 14:04:16 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int		number;
	t_stack	*up;
	t_stack	*down;

	up = *stack_a;
	while (up->number == 0 && up->next)
		up = up->next;
	down = up->next;
	number = up->number;
	up->number = down->number;
	down->number = number;
	refesh_index(stack_a);
	write(1, "sa\n", 3);
}

void	ra(t_stack **stack_a)
{
	int		up_number;
	t_stack	*up;
	t_stack	*down;

	up = *stack_a;
	while (up->number == 0 && up->next)
		up = up->next;
	up_number = up->number;
	while (up->next)
	{
		down = up->next;
		up->number = down->number;
		up = up->next;
	}
	up->number = up_number;
	refesh_index(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a)
{
	int		before_number;
	int		after_number;
	t_stack	*up;
	t_stack	*down;

	up = *stack_a;
	while (up->number == 0 && up->next)
		up = up->next;
	before_number = up->number;
	while (up->next)
	{
		down = up->next;
		after_number = down->number;
		down->number = before_number;
		before_number = after_number;
		up = up->next;
	}
	down = *stack_a;
	while (down->number == 0 && down->next)
		down = down->next;
	down->number = before_number;
	refesh_index(stack_a);
	write(1, "rra\n", 4);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*up_a;
	t_stack	*up_b;

	up_a = *stack_a;
	while (up_a->next)
	{
		if (up_a->next->number == 0)
			up_a = up_a->next;
		else
			break ;
	}
	up_b = *stack_b;
	while (up_b->next)
	{
		if (up_b->number == 0)
			up_b = up_b->next;
		else
			break ;
	}
	up_a->number = up_b->number;
	up_b->number = 0;
	refesh_index(stack_a);
	refesh_index(stack_b);
	write(1, "pa\n", 3);
}
