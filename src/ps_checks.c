/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:58:38 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 14:07:09 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current->next)
	{
		current = current->next;
		if (current->number >= INT_MAX || current->number <= INT_MIN)
		{
			ft_printf("Error");
			free_list(*stack_a);
			exit(1);
		}
	}
}

void	check_duplicates(t_stack **stack_a)
{
	int		checking;
	t_stack	*current;

	current = *stack_a;
	while (current->next)
	{
		checking = current->number;
		current = current->next;
		if (checking == current->number)
		{
			free_list(*stack_a);
			ft_printf("Error");
			exit(1);
		}
	}
}

int	check_words(const char *word)
{
	int	count;

	count = 0;
	while (word[count])
	{
		if (word[count] == '-' && count == 0 && ft_isdigit(word[count + 1]))
			count++;
		else if (word[count] == '-' && word[count - 1] == ' ' \
		&& (ft_isdigit(word[count + 1]) && word[count + 1] != '\0'))
			count++;
		else if (ft_isdigit(word[count]))
			count++;
		else if (word[count] == ' ')
			count++;
		else
			return (0);
	}
	return (1);
}

void	check_argv(const char *argv[])
{
	int	current_arg;

	current_arg = 1;
	while (argv[current_arg])
	{
		if (check_words(argv[current_arg]) == 1)
			current_arg++;
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}
