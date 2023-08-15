/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 01:35:16 by agaley            #+#    #+#             */
/*   Updated: 2023/08/15 22:32:33 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *env)
{
	env->iter = 25;
	env->xoff = env->w / 2;
	env->yoff = env->h / 2;
	env->x0 = env->xoff;
	env->y0 = env->yoff;
	env->zoom = env->xoff;
	env->zoom_step = env->xoff / 2;
	env->wzoom = env->xoff;
	env->hzoom = env->yoff;
}
