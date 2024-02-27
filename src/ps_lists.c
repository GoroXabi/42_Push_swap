/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:30:31 by xortega           #+#    #+#             */
/*   Updated: 2024/02/20 14:01:57 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_list(t_stack **stack_a, t_stack **stack_b, int total_ints)
{
	t_stack	*current_b;
	t_stack	*current_a;
	int		cubo;
	int		spaces;

	current_a = *stack_a;
	current_b = *stack_b;
	ft_printf("[index]\t[stack_a]\t[index]\t[stack_b]\n");
	while (current_a)
	{
		ft_printf("[%d]", current_a->position);
		if (current_a->number == 0)
			ft_printf("\t");
		spaces = total_ints;
		while(spaces > (current_a->position))
		{
			spaces /= 10;
			ft_printf(" ");
		}
		ft_printf("|");
		cubo = -1;
		spaces = 1;
		while (++cubo < current_a->number)
			ft_printf("▧");
		while(spaces <=  total_ints - (current_a->number))
		{
			spaces++;
			ft_printf(" ");
		}
		ft_printf("[%d]", current_b->position);
		cubo = -1;
		ft_printf("\t|");
		while (++cubo < current_b->number)
			ft_printf("▧");
		ft_printf("\n");
		current_a = current_a->next;
		current_b = current_b->next;
	}
	ft_printf("\n");
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
void cp_stack(t_stack **src, t_stack **dst)
{
	t_stack *current_src;

	current_src = *src;
	while (current_src)
	{
		new_node(current_src->number, current_src->position, dst);
		current_src = current_src->next;
	}
}
void new_node(int number, int position,  t_stack **stack)
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