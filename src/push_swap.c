/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:16:18 by xortega           #+#    #+#             */
/*   Updated: 2024/03/01 17:09:41 by xortega          ###   ########.fr       */
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

int	is_sort(t_stack **stack_a)
{
	t_stack	*a;
	int	n;

	a = *stack_a;
	n = 1;
	while (a->number == 0 && a->next)
	{
		n++;	
		a = a->next;
	}
	if (a->number == 0)
		return(0);
	while (a->next)
	{
		if(a->number != n)
			return(0);
		n++;
		a = a->next;
	}
	return(1);
}

int	main(int argc, char const *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_buffer *movements;
	int 	total_ints;


	if (argc == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	check_argv(argv);
	stack_a = NULL;
	stack_b = NULL;
	movements = NULL;
	total_ints = get_ints(argv, argc, &stack_a);
	check_duplicates(&stack_a);
	stack_a = indexing_ints(total_ints, &stack_a);
	init_stack_b(total_ints, &stack_b);
	if (!is_sort(&stack_a))
	{
		if (total_ints == 2)
			sa(&stack_a);
		//else if (total_ints == 3)
		//	case_3(&stack_a);
		else	
			algoritmo_cutre2(&stack_a, &stack_b, &movements, total_ints);
	}
	//if (total_ints == 3)
	//	case_3(&stack_a);
	//if (total_ints == 5)
	//	case_5(&stack_a, &stack_b, total_ints);
	//print_list(&stack_a, &stack_b, total_ints);
	free_list(stack_a);
	free_list(stack_b);
	//system("leaks push_swap");
	return (0);
}
//algoritmo