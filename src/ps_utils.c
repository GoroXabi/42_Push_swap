/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:31:44 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 13:33:10 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*base(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

t_stack	*tip(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
	{
		if (current->number == 0)
			current = current->next;
		else
			break ;
	}
	return (current);
}

int	left_in_stack(t_stack **stack)
{
	t_stack	*current;

	current = tip(stack);
	while (current->next)
		current = current->next;
	return (current->position);
}

int	is_sort(t_stack **stack)
{
	t_stack	*a;
	int		n;

	a = *stack;
	n = 1;
	while (a->number == 0 && a->next)
	{
		n++;
		a = a->next;
	}
	if (a->number == 0)
		return (0);
	while (a->next)
	{
		if (a->number != n)
			return (0);
		n++;
		a = a->next;
	}
	return (1);
}
