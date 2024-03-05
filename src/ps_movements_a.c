/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:14 by xortega           #+#    #+#             */
/*   Updated: 2024/03/05 12:44:28 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa: swap_a; intercambia primera y segunda posicion del stack a;
void	sa(t_stack **stack_a)
{
	int	number;
	t_stack *up;
	t_stack *down;

	up = *stack_a;
	while (up->number == 0 && up->next)
		up = up->next;
	down = up->next;
	number = up->number;
	up->number = down->number;
	down->number = number;
	refesh_index(stack_a);
	ft_printf("sa\n");
}
//ra: rotate_a; desplaza todos los argumentos del stack a una posicion hacia arrba, el primero pasando a ser el ultimo;
void	ra(t_stack **stack_a, t_buffer **movements)
{
	int up_number;
	t_stack *up;
	t_stack *down;

	up = *stack_a;
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
	refesh_index(stack_a);
	buffer(movements, 1);
}

//rra: reverse_rotate_a; desplaza todos los argumentos del stack a una posicion hacia abajo, el ultimo pasando a ser el primero;
void	rra(t_stack **stack_a, t_buffer **movements)
{
	int		before_number;
	int		after_number;
	t_stack *up;
	t_stack *down;

	up = *stack_a;
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
	down = *stack_a;
	while (down->number == 0 && down->next)
		down = down->next;
	down->number = before_number;
	refesh_index(stack_a);
	buffer(movements, 3);
}
//pa: push_a; pasa el argumento mas arriba del stack b a encima del argumento mas arriba del stack a;
void	pa(t_stack **stack_a, t_stack **stack_b, t_buffer **movements)
{
	t_stack	*up_a;
	t_stack	*up_b;

	up_a = *stack_a;
	while (up_a->next)
	{
		if (up_a->next->number == 0)
			up_a = up_a->next;
		else
			break;
	}
	up_b = *stack_b;
	while (up_b->next)
	{
		if (up_b->number == 0)
			up_b = up_b->next;
		else
			break;
	}
	up_a->number = up_b->number;
	up_b->number = 0;
	refesh_index(stack_a);
	refesh_index(stack_b);
	buffer(movements, -1);
}
