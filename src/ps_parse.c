/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:34:31 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 14:06:29 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_to_index(int srch, int index, t_stack **obj, t_stack **src)
{
	t_stack	*current_obj;
	t_stack	*current_src;

	current_obj = *obj;
	current_src = *src;
	while (current_src->number != srch && current_src->next)
	{
		current_obj = current_obj->next;
		current_src = current_src->next;
	}
	current_obj->number = index;
}

t_stack	*indexing_ints(int total_ints, t_stack **stack_a)
{
	t_stack	*new_stack;
	t_stack	*c_stack_a;
	int		big;
	int		small;
	int		count;

	big = INT_MAX;
	count = -1;
	new_stack = NULL;
	c_stack_a = *stack_a;
	cp_stack(stack_a, &new_stack);
	while (++count < total_ints)
	{
		small = INT_MIN;
		while (c_stack_a)
		{
			if (small < c_stack_a->number && c_stack_a->number < big)
				small = c_stack_a->number;
			c_stack_a = c_stack_a->next;
		}
		big = small;
		change_to_index(big, (total_ints - count), &new_stack, stack_a);
		c_stack_a = *stack_a;
	}
	return (free_list(*stack_a), new_stack);
}

void	free_splited(char **splited)
{
	int	i;

	i = -1;
	while (splited[++i])
		free(splited[i]);
	free(splited);
}

int	get_ints(const char *argv[], int argc, t_stack **stack_a)
{
	char	**splited_argv;
	int		current_arg;
	int		c_word;
	int		total_ints;

	current_arg = 1;
	total_ints = 0;
	c_word = 0;
	while (current_arg < argc)
	{
		splited_argv = ft_split(argv[current_arg], ' ');
		while (splited_argv[c_word])
		{
			new_node(ft_atoi(splited_argv[c_word]), total_ints + 1, stack_a);
			c_word++;
			total_ints++;
		}
		free_splited(splited_argv);
		c_word = 0;
		current_arg++;
	}
	return (total_ints);
}

void	init_stack_b(int total_ints, t_stack **stack_b)
{
	int	current_int;

	current_int = 0;
	while (++current_int <= total_ints)
		new_node(0, 0, stack_b);
}
