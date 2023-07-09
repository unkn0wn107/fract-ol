/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:54:43 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:03:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	solve(t_stack *stack_a)
{
	t_stack	stack_b;
	void	(*fun)(t_stack*, t_stack*);

	if (stack_size(stack_a) == 1 || check_result(stack_a) == 0)
		return ;
	fun = select_algo(stack_a);
	if (!fun)
		exit_error(10, stack_a, NULL, NULL);
	else
	{
		stack_b.id = 'b';
		stack_b.head = NULL;
		(*fun)(stack_a, &stack_b);
		stack_free(&stack_b);
	}
}

void	*select_algo(t_stack *stack)
{
	if (stack_size(stack) == 2)
		return (&algo_2);
	if (stack_size(stack) == 3)
		return (&algo_3);
	if (stack_size(stack) <= 5)
		return (&algo_5);
	if (stack_size(stack) > 5)
		return (&algo_radix);
	return (NULL);
}

int	check_result(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		exit_error(11, NULL, NULL, NULL);
	else
	{
		node = stack->head;
		while (node->next)
		{
			if (node->value > node->next->value)
				return (1);
			node = node->next;
		}
	}
	return (0);
}
