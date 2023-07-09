/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:14:23 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:03:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Return size of stack
 *
 * @param stack pointer towards stack anchor
 * @return size of stack
 */
size_t	stack_size(t_stack *stack)
{
	size_t	i;
	t_node	*last;

	if (!stack || !stack->head)
		return (0);
	last = stack->head;
	i = 0;
	if (last)
		i++;
	while (last && last->next)
	{
		last = last->next;
		i++;
	}
	return (i);
}

/**
 * Return n-th node from last node in a stack, last for 0
 *
 * @param stack pointer towards stack anchor
 * @param n index of node from last node
 * @return first node in stack
 */
t_node	*stack_last_n(t_stack *stack, size_t n)
{
	size_t	i;
	size_t	size;
	t_node	*last_n;

	if (!stack)
		return (NULL);
	size = stack_size(stack);
	if (n >= size)
		return (NULL);
	i = 1;
	last_n = stack->head;
	while (i++ < size - n)
		last_n = last_n->next;
	return (last_n);
}

/**
 * Return last node in a stack
 *
 * @param stack pointer towards stack anchor
 * @return first node in stack
 */
t_node	*stack_last(t_stack *stack)
{
	return (stack_last_n(stack, 0));
}
