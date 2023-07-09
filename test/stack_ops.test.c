/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:06:59 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// -1 if stack is NULL
// 1 if stack has less than 2 nodes
// 0 otherwise
// Reverse rotate stack and verify result
int	test_stack_rrotate(void)
{
	t_stack	s;
	t_stack	*stack;

	stack = &s;
	if (stack_rrotate(NULL) != -1)
		return (ft_printf("stack_rrotate : no return -1 on NULL\n"), -1);
	stack_init(stack, 'a');
	if (stack_rrotate(stack) != 1)
		return (ft_printf("stack_rrotate : no return 1 if stack < 2n\n"), -1);
	stack_add(stack, 1);
	if (stack_rrotate(stack) != 1)
		return (ft_printf("stack_rrotate : no return 1 if stack < 2n\n"), -1);
	stack_add(stack, 2);
	stack_add(stack, 3);
	if (stack_rrotate(stack) != 0)
		return (ft_printf("stack_rrotate : no return 0 for success\n"), -1);
	if (stack->head->value != 1 || stack->head->next->value != 3
		|| stack->head->next->next->value != 2)
		return (ft_printf("stack_rrotate : doesn't rotate nodes\n"), -1);
	stack_free(stack);
	printf("stack_rrotate: OK\n");
	return (0);
}
