/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:59:29 by xortega           #+#    #+#             */
/*   Updated: 2024/03/01 17:03:09 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sb: swap_b; intercambia primera y segunda posicion del stack b;
void	sb(t_stack **stack_b)
{
	int	number;
	t_stack *up;
	t_stack *down;

	up = *stack_b;
	while (up->number == 0 && up->next)
		up = up->next;
	down = up->next;
	number = up->number;
	up->number = down->number;
	down->number = number;
	refesh_index(stack_b);
	ft_printf("sb\n");
}
//rb: rotate_b; desplaza todos los argumentos del stack b una posicion hacia arrba, el primero pasando a ser el ultimo;
void	rb(t_stack **stack_b, t_buffer **movements)
{
	int up_number;
	t_stack *up;
	t_stack *down;

	up = *stack_b;
	while (up->number == 0 && up->next)
		up = up->next;
	up_number = up->number;
	while(up->next)
	{
		down = up->next;
		up->number = down->number;
		up = up->next;
	}
	up->number = up_number;
	refesh_index(stack_b);
	buffer(movements, 2);
}

//rrb: reverse_rotate_b; desplaza todos los argumentos del stack b una posicion hacia abajo, el ultimo pasando a ser el primero;
void	rrb(t_stack **stack_b, t_buffer **movements)
{
	int		before_number;
	int		after_number;
	t_stack *up;
	t_stack *down;

	up = *stack_b;
	while (up->number == 0 && up->next)
		up = up->next;
	before_number = up->number;
	while(up->next)
	{
		down = up->next;
		after_number = down->number;
		down->number = before_number;
		before_number = after_number;
		up = up->next;
	}
	down = *stack_b;
	while (down->number == 0 && down->next)
		down = down->next;
	down->number = before_number;
	refesh_index(stack_b);
	buffer(movements, 4);
}
//pb: push_b; pasa el argumento mas arriba del stack a encima del argumento mas arriba del stack b;
void	pb(t_stack **stack_a, t_stack **stack_b, t_buffer **movements)
{
	t_stack	*up_a;
	t_stack	*up_b;

	up_a = *stack_a;
	while (up_a->next)
	{
		if (up_a->number == 0)
			up_a = up_a->next;
		else
			break;
	}
	up_b = *stack_b;
	while (up_b->next)
	{
		if (up_b->next->number == 0)
			up_b = up_b->next;
		else
			break;
	}
	up_b->number = up_a->number;
	up_a->number = 0;
	refesh_index(stack_a);
	refesh_index(stack_b);
	buffer(movements, 0);
}