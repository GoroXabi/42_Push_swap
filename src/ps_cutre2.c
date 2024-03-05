/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cutre2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:30:32 by xortega           #+#    #+#             */
/*   Updated: 2024/03/05 12:22:43 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
int	left_in_stack(t_stack **stack)
{
	t_stack	*current;

	current = tip(stack);
	while (current->next)
			current = current->next;
	return (current->position);
}

t_stack	*base(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
		current = current->next;
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
t_stack	*find_position(t_stack **stack, int position)
{
	t_stack	*current;
	
	current = tip(stack);
	while (current)
	{
		if (current->position == position)
			return(current);
		current = current->next;
	}
	return(current);
}

t_stack *init_foe(void)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->number = INT_MAX;
	node->position = 0;
	return (node);
}
t_stack	*find_close_to_small(t_stack **stack, int total_ints, int room_up, int threshold)
{
	t_stack	*current;
	t_stack	*anti_foe;
	t_stack	*foe;
	int room_down;

	if (room_up >= left_in_stack(stack))
		return(find_small(stack));
	current = tip(stack);
	foe = init_foe();
	anti_foe = init_foe();
	room_down = (left_in_stack(stack) - room_up);
	while(current)
	{
		if (current->number < foe->number && current->number < threshold && current->position < room_up && current->number < total_ints - 3)
		{
			if (foe->number == INT_MAX)
				free(foe);
			foe = current;
		}
		if (current->number < anti_foe->number && current->number < threshold && current->position > room_down && current->number < total_ints - 3)
		{
			if (anti_foe->number == INT_MAX)
				free(anti_foe);
			anti_foe = current;
		}
		current = current->next;
	}
//	if (anti_foe->number == 0)
//		free(anti_foe);
	if (foe->number == INT_MAX && anti_foe->number == INT_MAX)
		return(find_close_to_small(stack, total_ints, room_up + 10, threshold));
	else if (foe->position <= (left_in_stack(stack) - anti_foe->position))
		return(foe);
	else if (foe->position > (left_in_stack(stack) - anti_foe->position))
		return(anti_foe);
//	if (foe->position < anti_foe->position - left_in_stack(stack))
//		return(foe);
//	if (foe->position > anti_foe->position - left_in_stack(stack))
//		return(anti_foe);
	return(foe);
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
void	up_small(t_stack **stack_a, t_buffer **movements)
{
	while (tip(stack_a)->number != find_small(stack_a)->number)
	{
		if (is_sort(stack_a))
			break;
		if (find_small(stack_a)->position > ((left_in_stack(stack_a)) / 2)
		&& find_small(stack_a)->position > 2)
			rra(stack_a, movements);
		else
			ra(stack_a, movements);
	}
}
void	up_close_to_small(t_stack **stack_a, t_buffer **movements, int threshold, int total_ints)
{	
	t_stack *to_up;
	int		to_up_num;
	int		tip_a;

	to_up = find_close_to_small(stack_a, total_ints, 10, threshold);
	to_up_num = to_up->number;
	if (to_up_num == 0 || to_up_num > total_ints)
	{
		free(to_up);
		up_small(stack_a, movements);
		return ;
	}
	tip_a = tip(stack_a)->number;
	while (tip_a != to_up_num)
	{
		if (to_up->position >= left_in_stack(stack_a)/2)
			rra(stack_a, movements);
		else
			ra(stack_a, movements);
		tip_a = tip(stack_a)->number;
	}
}
void	up_by_num_b(t_stack **stack_b, t_buffer **movements, int number)
{
	t_stack	*current;

	current = tip(stack_b);
	while (current)
	{
		if (current->number == number)
			break ;
		current = current->next;
	}
	if (!current)
		return ;
	while (tip(stack_b)->number != number)
	{
		if (is_sort(stack_b))
			break;
		if (current->position > ((left_in_stack(stack_b)) / 2) && current->position > 2)
			rrb(stack_b, movements);
		else
			rb(stack_b, movements);
	}
}
void	down_by_num_b(t_stack **stack_b, t_buffer **movements, int number)
{
	t_stack	*current;

	current = tip(stack_b);
	while (current)
	{
		if (current->number == number)
			break ;
		current = current->next;
	}
	if (!current)
		return ;
	while (base(stack_b)->number != number)
	{
		if (is_sort(stack_b))
			break;
		if (current->position > ((left_in_stack(stack_b)) / 2) && current->position > 2)
			rra(stack_b, movements);
		else
			ra(stack_b, movements);
	}
}
void search_close_b(t_stack **stack_b, t_buffer **movements, int number)
{
	t_stack	*current;
	//int		up_3;
	//int		down_3;
	
	current = tip(stack_b);
	//up_3 = (t_ints/3);
	//down_3 = ((t_ints/3) * 2);
	while (current)
	{
		if (current->number == number - 1)// && ((current->position < up_3) || current->position > down_3))
			up_by_num_b(stack_b, movements, (number - 1));
		else if (current->number == number + 1)// && (current->position < up_3 || current->position > down_3))
			down_by_num_b(stack_b, movements, (number + 1));
		current = current->next;
	}
}
void search_next_b(t_stack **stack_b, t_buffer **movements, int number)
{
	t_stack	*current;
	int		foe;
	
	current = tip(stack_b);
	foe = 0;
	while (current)
	{
		if (current->number > foe && current->number < number)
			foe = current->number;
		current = current->next;
	}
	up_by_num_b(stack_b, movements, foe);
}
void	case_3_bottom(t_stack **stack_a, int total_ints, t_buffer **movements)
{
	t_stack	*a;

	a = tip(stack_a);
	if (a->number == total_ints - 2 && !is_sort(stack_a))
	{
		sa(stack_a);
		ra(stack_a, movements);
	}
	else if (a->number == total_ints - 1)
	{
		if (a->next->number == total_ints - 2)
			sa(stack_a);
		else
			rra(stack_a, movements);
	}
	else if (a->number == total_ints)
	{
		if (a->next->number == total_ints - 2)
			ra(stack_a, movements);
		else
		{	
			sa(stack_a);
			rra(stack_a, movements);
		}
	}
}
void back_to_a(t_stack **stack_a, t_stack **stack_b, t_buffer **movements)
{	
	while (left_in_stack(stack_b) > 0)
	{
		up_by_num_b(stack_b, movements, find_large(stack_b)->number);
		pa(stack_a, stack_b, movements);
	}
}
int cost_cmp(int n1, int n2, int ints_left)
{
	if (n1 < ints_left/3 && n2 < ints_left/3)
	{
		if (n1 < n2)
			return (0);
		return (1);
	}	
	if (n1 < (ints_left/3) * 2 && n2 < (ints_left/3) * 2)
	{
		//no esta hecha esta condicional
		if (n1 < n2)
			return (0);
		return (1);
	}
	if (n1 > (ints_left/3) * 2 && n2 > (ints_left/3) * 2)
	{
		if (n1 < n2)
			return (1);
		return (0);
	}
	if ((n1 < (ints_left/3) * 2 && n1 > (ints_left/3)) 
	&& (n2 > (ints_left/3) * 2 || n2 < (ints_left/3)))
		return(1);
	if ((n2 < (ints_left/3) * 2 && n2 > (ints_left/3)) 
	&& (n1 > (ints_left/3) * 2 || n1 < (ints_left/3)))
		return(0);
	if (n1 < (ints_left/3) && n2 > (ints_left/3) * 2)
	{
		if (n1 < ints_left - n2)
			return (0);
		return(1);
	}	if (n2 < (ints_left/3) && n1 > (ints_left/3) * 2)
	{
		if (n1 > ints_left - n2)
			return (0);
		return(1);
	}
	return(0);
}
void cost_check(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*foe1;
	t_stack	*foe2;
	int		number1;
	int		number2;

	number1 = tip(stack_a)->number;
	number2 = tip(stack_a)->next->number;
	current = tip(stack_b);
	foe1 = *stack_b;
	foe2 = *stack_b;
	while (current)
	{
		if (current->number > foe1->number && current->number < number1)
			foe1 = current;
		if (current->number > foe2->number && current->number < number2)
			foe2 = current;
		current = current->next;
	}
	if (cost_cmp(foe1->position, foe2->position, left_in_stack(stack_b)))
		sa(stack_a);
}
//void buble(t_stack **stack_a, int total_ints)
//{
//	t_stack	*current;
//
//	current = tip(stack_a);
//	while(!is_sort(stack_a))
//	{
//		if (current->number < current->next->number || current->number == total_ints)
//			ra(stack_a);
//		else
//			sa(stack_a);
//	}
//
//}
void algoritmo_cutre2(t_stack **stack_a, t_stack **stack_b,  t_buffer **movements, int total_ints)
{
	int  threshold;
	
	threshold = total_ints/2;
	while (left_in_stack(stack_a) > threshold && total_ints > 7)
	{
		up_close_to_small(stack_a, movements, threshold, total_ints);
		search_next_b(stack_b, movements, tip(stack_a)->number);
		pb(stack_a, stack_b, movements);
	}
	threshold = total_ints - 3;
	while (left_in_stack(stack_a) > 3 && total_ints > 7)
	{
		up_close_to_small(stack_a, movements, threshold, total_ints);
		search_next_b(stack_b, movements, tip(stack_a)->number);
		pb(stack_a, stack_b, movements);
	}
//	print_list(stack_a, stack_b, total_ints);
	case_3_bottom(stack_a, total_ints, movements);
//	print_list(stack_a, stack_b, total_ints);
	back_to_a(stack_a, stack_b, movements);
}
