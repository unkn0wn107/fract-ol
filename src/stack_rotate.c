/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:18:06 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:03:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Rotate stack
 *
 * @param stack pointer towards stack anchor
 * @return -1 if stack is NULL, 1 if stack has less than 2 nodes, 0 otherwise
 */
int	stack_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack)
		return (-1);
	first = stack->head;
	if (!first || !first->next)
		return (1);
	last = stack->head;
	while (last->next)
		last = last->next;
	stack->head = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("r%c\n", stack->id);
	return (0);
}

/**
 * Rotate 2 stacks
 *
 * @param stack pointer towards stack anchor
 * @return -1 if stack is NULL, 1 if stack has less than 2 nodes, 0 otherwise
 */
int	stack_rotate2(t_stack *stack1, t_stack *stack2)
{
	int	response;

	response = stack_rotate(stack1);
	if (response != 0)
		return (response);
	response = stack_rotate(stack2);
	return (response);
}

/**
 * Reverse rotate stack
 *
 * @param stack pointer towards stack anchor
 * @return -1 if stack is NULL, 1 if stack has less than 2 nodes, 0 otherwise
 */
int	stack_rrotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack)
		return (-1);
	first = stack->head;
	if (!first || !first->next)
		return (1);
	last = stack_last(stack);
	stack_last_n(stack, 1)->next = NULL;
	stack->head = last;
	last->next = first;
	ft_printf("rr%c\n", stack->id);
	return (0);
}

/**
 * Reverse rotate 2 stacks
 *
 * @param stack pointer towards stack anchor
 * @return -1 if stack is NULL, 1 if stack has less than 2 nodes, 0 otherwise
 */
int	stack_rrotate2(t_stack *stack1, t_stack *stack2)
{
	int	response;

	response = stack_rrotate(stack1);
	if (response != 0)
		return (response);
	response = stack_rrotate(stack2);
	return (response);
}
