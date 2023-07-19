/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:46 by agaley            #+#    #+#             */
/*   Updated: 2023/07/19 18:47:44 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_zoom(int key, t_env *env)
{
	int	r;

	r = mlx_mouse_get_pos(env->mlxptr, env->winptr, &env->xm, &env->ym);
	if (r == 0 && env->xm == 0 && env->ym == 0)
		return ;
	env->xf = env->xm;
	env->yf = env->ym;
	if (key == MOUSE_UP && env->zoom <= MAX_ZOOM)
		env->zoom += 1;
	else if (key == MOUSE_DOWN && env->zoom >= 0)
		env->zoom -= 1;
	render_fractal(env);
}
