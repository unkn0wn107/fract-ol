/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:03:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Swap first and second nodes in a stack
 * unit tested
 *
 * @param stack pointer towards stack anchor
 * @return -1 if stack is NULL, 1 if stack has less than 2 nodes, 0 otherwise
 */
int	stack_swap(t_stack	*stack)
{
	t_node	*first;

	if (!stack)
		return (-1);
	first = stack->head;
	if (!first || !first->next)
		return (1);
	stack->head = first->next;
	first->next = stack->head->next;
	stack->head->next = first;
	ft_printf("s%c\n", stack->id);
	return (0);
}

/**
 * Swap first and second nodes in 2 stacks
 *
 * @param stack1 pointer towards stack1 anchor
 * @param stack2 pointer towards stack2 anchor
 * @return -1 if a stack is NULL, 1 if a stack has less than 2 nodes, 0 otherwise
 */
int	stack_swap2(t_stack *stack1, t_stack *stack2)
{
	int	response;

	response = stack_swap(stack1);
	if (response != 0)
		return (response);
	response = stack_swap(stack2);
	return (response);
}

/**
 * Push first node of stack1 to stack2
 * unit tested
 *
 * @param stack1 pointer towards stack1 anchor
 * @param stack2 pointer towards stack2 anchor
 * @return -1 if a stack is NULL, 1 if stack1 is empty, 0 otherwise
 */
int	stack_push(t_stack *stack1, t_stack *stack2)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack1 || !stack2)
		return (-1);
	node1 = stack1->head;
	if (!node1)
		return (1);
	node2 = stack2->head;
	stack2->head = node1;
	stack1->head = node1->next;
	node1->next = node2;
	ft_printf("p%c\n", stack2->id);
	return (0);
}
