/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:59:29 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 13:56:39 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b)
{
	int		number;
	t_stack	*up;
	t_stack	*down;

	up = *stack_b;
	while (up->number == 0 && up->next)
		up = up->next;
	down = up->next;
	number = up->number;
	up->number = down->number;
	down->number = number;
	refesh_index(stack_b);
	write(1, "sb\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*up_a;
	t_stack	*up_b;

	up_a = tip(stack_a);
	up_b = *stack_b;
	while (up_b->next != tip(stack_b))
		up_b = up_b->next;
	up_b->number = up_a->number;
	tip(stack_a)->number = 0;
	refesh_index(stack_a);
	refesh_index(stack_b);
	write(1, "pb\n", 3);
}
