/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:25:08 by agaley            #+#    #+#             */
/*   Updated: 2023/05/11 00:37:03 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int	ret;

	ret = 0;
	if (test_stack_swap() != 0)
		ret = 1;
	if (test_stack_push() != 0)
		ret = 1;
	if (test_stack_rotate() != 0)
		ret = 1;
	if (test_stack_rrotate() != 0)
		ret = 1;
	return (ret);
}
