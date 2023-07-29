/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:56:32 by agaley            #+#    #+#             */
/*   Updated: 2023/07/29 02:35:40 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	g_failed = 0;

// Always OK
int	test_create_2d_array(void)
{
	ssize_t	width;
	ssize_t	height;
	ssize_t	i;
	ssize_t	j;
	double	**array;

	g_failed = 0;
	width = 5;
	height = 5;
	i = 0;
	array = create_2d_array(width, height);
	if (array == NULL)
		handle_exit(EXIT_FAILURE, MSG_ERR_MEMORY, NULL);
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			if (array[i][j] != 0)
				report_result(0, MSG_ERR_ARRAY_NOT_ZERO, g_failed);
			j++;
		}
		i++;
	}
	return (g_failed);
}
