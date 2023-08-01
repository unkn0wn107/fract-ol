/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 01:31:01 by agaley            #+#    #+#             */
/*   Updated: 2023/07/29 21:12:32 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	**create_zoom_matrix(size_t width, size_t height, t_env *env)
{
	size_t	row;
	size_t	col;
	double	**m;

	m = malloc(height * sizeof(double *));
	if (!m)
		return (NULL);
	row = 0;
	while (row < height)
	{
		m[row] = malloc(2 * width * sizeof(double));
		if (!m[row])
		{
			while (row--)
				free(m[row]);
			return (free(m), NULL);
		}
		col = 0;
		while (col < width)
		{
			m[row][col] = env->x0f - env->x0 + col * (2.0 * env->zoom) / width;
			m[row][col] = env->y0f - env->y0 + row * (2.0 * env->zoom) / height;
			col++;
		}
		row++;
	}
	return (m);
}
