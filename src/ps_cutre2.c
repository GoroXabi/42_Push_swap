/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cutre2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:30:32 by xortega           #+#    #+#             */
/*   Updated: 2024/02/27 13:33:59 by xortega          ###   ########.fr       */
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
t_stack	*find_close_to_small(t_stack **stack, int total_ints)
{
	t_stack	*current;
	int		anti_foe;
	int		foe;

	current = tip(stack);
	anti_foe = total_ints;
	foe = 0;
	while(current)
	{
		if (current->number <= total_ints/2 && current->position >= foe)	
			foe = current->position;
		if (current->number <= total_ints/2 && current->position <= anti_foe)	
			anti_foe = current->position;
		//ft_printf("current->number : %d |current foe : %d|current anti_foe : %d\n", current->number, foe, anti_foe);
		current = current->next;
	}
	if (foe > (total_ints - anti_foe))
			return(find_position(stack, foe));
	else
			return(find_position(stack, anti_foe));
	return(current);
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
void	up_small(t_stack **stack_a)
{
	while (tip(stack_a)->number != find_small(stack_a)->number)
	{
		if (is_sort(stack_a))
			break;
		if (find_small(stack_a)->position > ((left_in_stack(stack_a)) / 2)
		&& find_small(stack_a)->position > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}
void	up_close_to_small(t_stack **stack_a, int t_ints)
{
	while (tip(stack_a)->number >= (t_ints/2))
	{
		if (is_sort(stack_a))
			break;
		if (find_close_to_small(stack_a, t_ints)->position > ((left_in_stack(stack_a)) / 2)
		&& find_close_to_small(stack_a, t_ints)->position > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}
void	up_by_num_b(t_stack **stack_b, int number)
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
			rra(stack_b);
		else
			ra(stack_b);
	}
}
void	down_by_num_b(t_stack **stack_b, int number)
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
			rra(stack_b);
		else
			ra(stack_b);
	}
}
void search_close_b(t_stack **stack_b, int number, int t_ints)
{
	t_stack	*current;
	int		up_3;
	int		down_3;
	
	current = tip(stack_b);
	up_3 = (t_ints/3);
	down_3 = ((t_ints/3) * 2);
	while (current)
	{
		if (current->number == number - 1)// && ((current->position < up_3) || current->position > down_3))
			up_by_num_b(stack_b, (number - 1));
		else if (current->number == number + 1)// && (current->position < up_3 || current->position > down_3))
			down_by_num_b(stack_b, (number + 1));
		current = current->next;
	}
}
void search_next_b(t_stack **stack_b, int number)
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
	up_by_num_b(stack_b, foe);
	}
void	case_3_bottom(t_stack **stack_a, int total_ints)
{
	t_stack	*a;

	a = tip(stack_a);
	if (a->number == total_ints - 2 && !is_sort(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (a->number == total_ints - 1)
	{
		if (a->next->number == total_ints - 2)
			sa(stack_a);
		else
			rra(stack_a);
	}
	if (a->number == total_ints)
	{
		if (a->next->number == total_ints - 2)
			ra(stack_a);
		else
		{	
			sa(stack_a);
			rra(stack_a);
		}
	}
}
void back_to_a(t_stack **stack_a, t_stack **stack_b)
{	
	while (left_in_stack(stack_b) > 0)
	{
		up_by_num_b(stack_b, find_large(stack_b)->number);
		pa(stack_a, stack_b);
	}
	
	
}
void algoritmo_cutre2(t_stack **stack_a, t_stack **stack_b, int total_ints)
{
	//ft_printf("close_to_small[0x][position][number]: [%p][%d][%d]\n", find_close_to_small(stack_a, total_ints), 
	//find_close_to_small(stack_a, total_ints)->position, find_close_to_small(stack_a, total_ints)->number);
	while (left_in_stack(stack_a) > (3))
	{
		if (tip(stack_a)->number <= total_ints - 3)
		{
			search_next_b(stack_b, tip(stack_a)->number);
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
	case_3_bottom(stack_a, total_ints);
	back_to_a(stack_a, stack_b);
}