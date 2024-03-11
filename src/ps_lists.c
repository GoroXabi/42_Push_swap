/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:30:31 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 13:35:52 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refesh_index(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 1;
	while (current)
	{
		if (current->number > 0)
			current->position = index++;
		else
			current->position = 0;
		current = current->next;
	}
}

void	free_list(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

void	cp_stack(t_stack **src, t_stack **dst)
{
	t_stack	*current_src;

	current_src = *src;
	while (current_src)
	{
		new_node(current_src->number, current_src->position, dst);
		current_src = current_src->next;
	}
}

void	new_node(int number, int position, t_stack **stack)
{
	t_stack	*node;
	t_stack	*head;

	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->number = number;
	node->position = position;
	if (!*stack)
		*stack = node;
	else
	{
		head = (*stack);
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = node;
		(*stack) = head;
	}
}
