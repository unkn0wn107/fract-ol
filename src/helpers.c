/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:35:16 by agaley            #+#    #+#             */
/*   Updated: 2023/08/02 01:35:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *env)
{
	env->w = WIN_WIDTH;
	env->h = WIN_HEIGHT;
	env->image = NULL;
	env->iter = 5;
	env->x0f = 0;
	env->y0f = 0;
	env->zoom = 1;
	palette_init(env);
}
