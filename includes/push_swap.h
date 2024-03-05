/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:58 by xortega           #+#    #+#             */
/*   Updated: 2024/03/02 10:30:26 by xortega          ###   ########.fr       */
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

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total_ints;
}				t_data;

//PARSE
void	change_to_index(int srch, int index, t_stack **obj, t_stack **src);
t_stack	*indexing_ints(int total_ints, t_stack **stack_a);
void	free_splited(char **splited);
int		get_ints(const char *argv[], int argc, t_stack **stack_a);
void	init_stack_b(int total_ints, t_stack **stack_b);
//LISTS
void	print_list(t_stack **stack_a, t_stack **stack_b, int total_ints);//BORRA
void	free_list(t_stack *stack);
void	cp_stack(t_stack **src, t_stack **dst);
void 	new_node(int number, int position,  t_stack **stack_a);
//CHECKS
int		check_words(const char *word);
void	check_duplicates(t_stack **stack_a);
void	check_argv(const char *argv[]);
//MOVEMENTS_A
void	sa(t_stack **stack_a);
void	ra(t_stack **stack_a, t_buffer **movements);
void	rra(t_stack **stack_a, t_buffer **movements);
void	pa(t_stack **stack_a, t_stack **stack_b, t_buffer **movements);
//MOVEMENTS_B
void	sb(t_stack **stack_b);
void	rb(t_stack **stack_b, t_buffer **movements);
void	rrb(t_stack **stack_b, t_buffer **movements);
void	pb(t_stack **stack_a, t_stack **stack_b, t_buffer **movements);
//MOVEMENTS_AB
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
//TRIVIAL_CASES
void	case_3(t_stack **stack_a);
void	case_5(t_stack **stack_a, t_stack **stack_b, int total_ints);
//SORT
int		is_sort(t_stack **stack_a);
void	refesh_index(t_stack **stack);
//ALGORITMO_CUTRE
void 	algoritmo_cutre(t_stack **stack_a, t_stack **stack_b, int total_ints);
//ALGORITMO_CUTRE2
t_stack	*tip(t_stack **stack);
void 	algoritmo_cutre2(t_stack **stack_a, t_stack **stack_b, t_buffer **movements, int total_ints);
//BUFFER
void 	buffer(t_buffer **movements, int instruction);
//pb 	= 0;
//ra	= 1;
//rb	= 2;
//rra	= 3;
//rrb	= 4;