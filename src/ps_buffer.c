/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:02:44 by xortega           #+#    #+#             */
/*   Updated: 2024/03/02 10:29:41 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void init_buffer(t_buffer **movements, int instruction)
{
	t_buffer	*node;
	
	node = malloc(sizeof(t_buffer));
	node->instruction = instruction;
	*movements = node;
}
void add_back_buffer(t_buffer **movements, int instruction)
{
	t_buffer	*node;
	t_buffer	*current;
	
	node = malloc(sizeof(t_buffer));
	node->instruction = instruction;
	node->next = NULL;
	current = *movements;
	if (current == NULL)
		*movements = node;
	else if (movements && *movements)
	{
		while (current->next)
			current = current->next;
		current->next = node;
	}
}

void	free_buffer(t_buffer **movements)
{
	t_buffer	*node;
	t_buffer	*next;
	
	node = *movements;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*movements = NULL;
}

int count_instructions(t_buffer **movements, int instruction)
{
	t_buffer	*current;
	int 		count;

	current = *movements;
	count = 0;
	while(current)
	{
		if (current->instruction == instruction)
			count++;
		current = current->next;
	}
	return (count);
}

void optimize_r(int ra, int rb)
{
	int rr;

	if (ra <= rb)
	{
		rr = ra;
		rb -= rr;
		while(rr-- > 0)
			ft_printf("rr\n");
		while(rb-- > 0)
			ft_printf("rb\n");
	}
	else
	{

		rr = rb;
		ra -= rr;
		while(rr-- > 0)
			ft_printf("rr\n");
		while(ra-- > 0)
			ft_printf("ra\n");
	}
}
void optimize_rr(int rra, int rrb)
{
	int rrr;

	if (rra <= rrb)
	{
		rrr = rra;
		rrb -= rrr;
		while(rrr-- > 0)
			ft_printf("rrr\n");
		while(rrb-- > 0)
			ft_printf("rrb\n");
	}
	else
	{

		rrr = rrb;
		rra -= rrr;
		while(rrr-- > 0)
			ft_printf("rrr\n");
		while(rra-- > 0)
			ft_printf("rra\n");
	}
}
void optimize(t_buffer **movements)
{
	int ra;
	int rb;
	int rra;
	int rrb;

	if (!movements)
		return ;
	ra = count_instructions(movements, 1);
	rb = count_instructions(movements, 2);
	rra = count_instructions(movements, 3);
	rrb = count_instructions(movements, 4);
	if (ra > 0 && rb > 0)
		optimize_r(ra, rb);
	else if (rra > 0 && rrb > 0)
		optimize_rr(rra, rrb);
	else
	{
		while(ra-- > 0)
			ft_printf("ra\n");
		while(rb-- > 0)
			ft_printf("rb\n");
		while(rra-- > 0)
			ft_printf("rra\n");
		while(rrb-- > 0)
			ft_printf("rrb\n");
	}
		
}
void buffer(t_buffer **movements, int instruction)
{
	if (instruction == 0 || instruction == -1)
	{
		if (*movements)
		{	
			optimize(movements);
			free_buffer(movements);	
		}
		if (instruction == 0)
			ft_printf("pb\n");
		else
			ft_printf("pa\n");
	}
	else
		add_back_buffer(movements, instruction);
}
//Caso 1 (llega un 0):
//*Optimiza*
//Se ejecuta toda la lista (salvo los push_b)
//Se libera la lista durante ejecución
//Creás una nueva lista.
//Que empieza en 0
//Head lista vieja -> Head lista nueva
