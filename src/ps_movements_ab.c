/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:59:29 by xortega           #+#    #+#             */
/*   Updated: 2024/03/01 16:52:59 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ss: swap_ab; intercambia primera y segunda posicion de los stacks a y b;
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	refesh_index(stack_a);
	refesh_index(stack_b);
	ft_printf("ss\n");
}

//rr: rotate_ab; desplaza todos los argumentos de los stacks a y b una posicion hacia arrba, el primero pasando a ser el ultimo;
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	
	ra(stack_a);
	rb(stack_b);
	refesh_index(stack_a);
	refesh_index(stack_b);
	ft_printf("rr\n");
}

//rrr: reverse_rotate_ab; desplaza todos los argumentos de los stacks a y b una posicion hacia abajo, el ultimo pasando a ser el primero;
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	refesh_index(stack_a);
	refesh_index(stack_b);
	ft_printf("rrr\n");
}
