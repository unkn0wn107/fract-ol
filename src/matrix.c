/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 01:31:01 by agaley            #+#    #+#             */
/*   Updated: 2023/07/29 02:49:20 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	**create_2d_array(ssize_t width, ssize_t height)
{
	ssize_t	row;
	ssize_t	col;
	double	**array;

	array = malloc(height * sizeof(double *));
	if (!array)
		return (NULL);
	row = 0;
	while (row < height)
	{
		array[row] = malloc(width * sizeof(double));
		if (!array[row])
		{
			while (row--)
				free(array[row]);
			return (free(array), NULL);
		}
		col = 0;
		while (col < width)
			array[row][col++] = 0.0;
		row++;
	}
	return (array);
}
