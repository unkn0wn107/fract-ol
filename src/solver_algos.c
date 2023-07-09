/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_algos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:57:49 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:03:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	algo_2(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->head->index > stack_a->head->next->index)
		stack_rotate(stack_a);
}

void	algo_3(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	while ((check_result(stack_a) != 0))
	{
		if (stack_a->head->index > stack_a->head->next->index
			&& stack_a->head->index > stack_a->head->next->next->index)
			stack_rotate(stack_a);
		else if (stack_a->head->index > stack_a->head->next->index)
			stack_swap(stack_a);
		else
			stack_rrotate(stack_a);
	}
}

void	algo_5(t_stack *stack_a, t_stack *stack_b)
{
	size_t	pivot;

	pivot = (stack_size(stack_a) - 1) / 2;
	while (stack_size(stack_a) > 3)
	{
		if (stack_a->head->index < pivot)
			stack_push(stack_a, stack_b);
		else
			stack_rotate(stack_a);
	}
	if (stack_b->head->next
		&& stack_b->head->index < stack_b->head->next->index)
		stack_swap(stack_b);
	algo_3(stack_a, stack_b);
	while (stack_b->head)
		stack_push(stack_b, stack_a);
}

void	algo_radix(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;
	size_t	i;
	size_t	bit;

	size = stack_size(stack_a);
	bit = 1;
	while (bit <= (size - 1))
	{
		i = 0;
		while (i < size)
		{
			if (!(stack_a->head->index & bit))
				stack_push(stack_a, stack_b);
			else
				stack_rotate(stack_a);
			i++;
		}
		while (stack_b->head)
			stack_push(stack_b, stack_a);
		bit = bit << 1;
	}
}
