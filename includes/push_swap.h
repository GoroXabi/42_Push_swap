/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:58 by xortega           #+#    #+#             */
/*   Updated: 2024/03/11 13:31:09 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

typedef struct s_stack
{
	int				number;
	int				position;
	struct s_stack	*next;
}				t_stack;

//PARSE
void	change_to_index(int srch, int index, t_stack **obj, t_stack **src);
t_stack	*indexing_ints(int total_ints, t_stack **stack_a);
void	free_splited(char **splited);
int		get_ints(const char *argv[], int argc, t_stack **stack_a);
void	init_stack_b(int total_ints, t_stack **stack_b);
//LISTS
void	free_list(t_stack *stack);
void	cp_stack(t_stack **src, t_stack **dst);
void	new_node(int number, int position, t_stack **stack_a);
//CHECKS
void	check_argv(const char *argv[]);
int		check_words(const char *word);
void	check_max_min(t_stack **stack_a);
void	check_duplicates(t_stack **stack_a);
//MOVEMENTS_A
void	sa(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
//MOVEMENTS_B
void	sb(t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//TRIVIAL_CASES
void	case_3(t_stack **stack_a, int total_ints);
void	case_5(t_stack **stack_a, t_stack **stack_b, int total_ints);
//INDEX
void	refesh_index(t_stack **stack);
//UTILS
t_stack	*tip(t_stack **stack);
t_stack	*base(t_stack **stack);
int		is_sort(t_stack **stack);
int		left_in_stack(t_stack **stack);
//RADIX
void	radix(t_stack **stack_a, t_stack **stack_b, int total_ints, int bit);