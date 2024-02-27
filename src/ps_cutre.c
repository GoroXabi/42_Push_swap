/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cutre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:30:32 by xortega           #+#    #+#             */
/*   Updated: 2024/02/20 12:26:13 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	stack_0(t_stack **stack)
{
	t_stack	*current;
	int		current_0;

	current = *stack;
	current_0 = 0;
	while (current->next)
	{
		if (current->number == 0)
		{
			current_0++;
			current = current->next;
		}
		else
			break;
	}
	return (current_0);
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
			break;
	}
	return (current);
}

t_stack	*find_small(t_stack **stack)
{
	t_stack	*current;
	t_stack	*winner;
	int		foe;

	current = *stack;
	foe = INT_MAX;	
	while (current)
	{
		if (foe > current->number && current->number > 0)
		{
			foe = current->number;
			winner = current;
		}
		if (current->next)
			current = current->next;
		else
			break;
	}
	if (current->number == 0)
		return (current);
	return (winner);
}
t_stack	*find_large(t_stack **stack)
{
	t_stack	*current;
	t_stack	*winner;
	int		foe;

	current = *stack;
	foe = 0;	
	while (current)
	{
		if (foe < current->number)
		{
			foe = current->number;
			winner = current;
		}
		if (current->next)
			current = current->next;
		else
			break;
	}
	if (current->number == 0)
		return (current);
	return (winner);
}
void	up_small(t_stack **stack_a, int t_ints)
{
	while (tip(stack_a)->number != find_small(stack_a)->number)
	{
		if (is_sort(stack_a))
			break;
		if (find_small(stack_a)->position > ((t_ints - stack_0(stack_a)) / 2)
		&& find_small(stack_a)->position > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}
void algoritmo_cutre(t_stack **stack_a, t_stack **stack_b, int total_ints)
{
	while (!is_sort(stack_a))
	{
		up_small(stack_a, total_ints);
		if (is_sort(stack_a))
			break;
		pb(stack_a, stack_b);
	}
	while((*stack_a)->number == 0)
		pa(stack_a, stack_b);
}
