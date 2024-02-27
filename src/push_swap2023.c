/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:16:18 by xortega           #+#    #+#             */
/*   Updated: 2024/02/02 13:07:15 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SUPERLIBFT/libft.h"

typedef struct s_data
{
	int	*stack_a;
	int	*stack_b;
	int	tip_a;		
	int	tip_b;
	int	total_ints;
}				t_data;


//sa: swap_a; intercambia primera y segunda posicion del stack a;
//sb: swap_b; intercambia primera y segunda posicion del stack b;
//ss: swap_ab; intercambia primera y segunda posicion del stack a y b;
//pa: push_a; pasa el argumento mas arriba del stack b a encima del argumento mas arriba del stack a;
//pb: push_b; pasa el argumento mas arriba del stack a a encima del argumento mas arriba del stack b;
//ra: rotate_a; desplaza todos los argumentos del stack a una posicion hacia arrba, el primero pasando a ser el ultimo;
//rb: rotate_b; desplaza todos los argumentos del stack b una posicion hacia arrba, el primero pasando a ser el ultimo;
//rr: rotate_ab; desplaza todos los argumentos del stack a y b una posicion hacia arrba, el primero pasando a ser el ultimo;
//rra: reverse_rotate_a; desplaza todos los argumentos del stack a una posicion hacia abajo, el ultimo pasando a ser el primero;
//rrb: reverse_rotate_b; desplaza todos los argumentos del stack b una posicion hacia abajo, el ultimo pasando a ser el primero;
//rrr: reverse_rotate_ab; desplaza todos los argumentos del stack a y b una posicion hacia abajo, el ultimo pasando a ser el primero;

void	sa(t_data *data)
{
	int	temp;

	if (data->tip_a < data->total_ints)
	{
		temp = data->stack_a[data->tip_a];
		data->stack_a[data->tip_a] = data->stack_a[data->tip_a + 1];
		data->stack_a[data->tip_a + 1] = temp;
	}
}

void	sb(t_data *data)
{
	int	temp;

	if (data->tip_b < data->total_ints)
	{
		temp = data->stack_b[data->tip_b];
		data->stack_b[data->tip_b] = data->stack_b[data->tip_b + 1];
		data->stack_b[data->tip_b + 1] = temp;
	}
}

void	ss(t_data *data)
{
	if (data->tip_b < data->total_ints && data->tip_a < data->total_ints)
	{
		sa(data);
		sb(data);
	}
}

void	pa(t_data *data)
{
	if (data->tip_b < (data->total_ints + 1))
	{
		data->stack_a[data->tip_a - 1] = data->stack_b[data->tip_b];
		data->tip_a--;
		data->tip_b++;
	}
}

void	pb(t_data *data)
{
	if (data->tip_a < (data->total_ints + 1))
	{
		data->stack_b[data->tip_b - 1] = data->stack_a[data->tip_a];
		data->tip_a++;
		data->tip_b--;
	}
}

void	ra(t_data *data)
{
	int	temp1;
	int	temp2;
	int	count;
	int	down;

	count = 0;
	down = data->total_ints;
	temp1 = data->stack_a[down];
	while (count < (data->total_ints - data->tip_a))
	{
		temp2 = data->stack_a[down - 1];
		data->stack_a[down - 1] = temp1;
		temp1 = 
		
	}
		
}

int	minus(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	i_atoi(const char *str, int k)
{
	static int	count = 0;
	int			c;
	int			m;
	int			j;

	if (k == 0)
		count = 0;
	c = 0;
	m = 1;
	j = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '-')
		count++;
	while (str[count] != ' ' && str[count] != '\n' \
	&& str[count] != '-' && str[count])
	{
		if (str[count] == '0')
			c *= 10;
		else
			c = (str[count] - 48) + (c * m);
		m *= 10;
		count++;
		j++;
	}
	return (c * minus(str[count - j - 1]));
}

int	count_ints(const char *str)
{
	int	count;
	int	n;

	n = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] == '-')
			count++;
		while (ft_isalnum(str[count]) == 1)
			count++;
		n++;
		while (str[count] == ' ')
			count++;
	}
	return (n);
}

void	fill_stack(int argc, const char **argv, int *stack, int total_ints)
{
	int	count_stack;
	int	count_argv;
	int	int_argv;
	int	j;

	count_stack = 0;
	count_argv = 1;
	while (count_stack < total_ints)
	{
		while (count_argv < argc)
		{
			j = 0;
			int_argv = count_ints(argv[count_argv]);
			while (int_argv > j)
			{
				stack[count_stack] = i_atoi(argv[count_argv], j);
				j++;
				count_stack++;
			}
			count_argv++;
		}
	}
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		n;

	if (argc == 1)
		return (0);
	data.total_ints = 0;
	n = 1;
	while (argc > n)
	{
		data.total_ints += count_ints(argv[n]);
		n++;
	}
	data.stack_a = malloc(sizeof(int) * data.total_ints);
	data.stack_b = malloc(sizeof(int) * data.total_ints);
	fill_stack(argc, argv, data.stack_a, data.total_ints);
	n = -1;
	while (data.total_ints > ++n)
		ft_printf("stack_a[%d]: %d\n", n, data.stack_a[n]);
	return (0);
}
