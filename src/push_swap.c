/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:16:18 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 14:06:20 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **stack_a, t_stack **stack_b, int total_ints)
{
	check_max_min(stack_a);
	check_duplicates(stack_a);
	*stack_a = indexing_ints(total_ints, stack_a);
	init_stack_b(total_ints, stack_b);
}

void	chose_case(t_stack **stack_a, t_stack **stack_b, int total_ints)
{
	if (total_ints == 2)
		sa(stack_a);
	else if (total_ints == 3)
		case_3(stack_a, total_ints);
	else if (total_ints <= 5)
		case_5(stack_a, stack_b, total_ints);
	else if (total_ints > 5)
		radix(stack_a, stack_b, total_ints, 0);
}

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total_ints;

	if (argc == 1 || (ft_strlen(argv[1]) == 1 && argv[1][0] == ' ') \
	|| ft_strlen(argv[1]) == 0)
		return (0);
	check_argv(argv);
	stack_a = NULL;
	stack_b = NULL;
	total_ints = get_ints(argv, argc, &stack_a);
	init(&stack_a, &stack_b, total_ints);
	if (!is_sort(&stack_a) && total_ints > 1)
		chose_case(&stack_a, &stack_b, total_ints);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
