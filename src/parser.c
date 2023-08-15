/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:30 by agaley            #+#    #+#             */
/*   Updated: 2023/08/15 19:08:39 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Parse parameters entered to control fractal choice and window size.
 *
 * @param argv argv from main.
 * @param env Environment variables.
 *
 * @returns None
 */
void	parse_args(char **argv, t_env *env)
{
	env->w = WIN_WIDTH;
	env->h = WIN_HEIGHT;
	if (argv[2])
		env->w = ft_atoi(argv[2]);
	if (argv[2] && argv[3])
		env->h = ft_atoi(argv[3]);
	env->hstr = ft_itoa(env->h);
	env->wstr = ft_itoa(env->w);
	if ((argv[2] && argv[3] && ft_strcmp(env->hstr, argv[3]) != 0)
		|| (argv[2] && ft_strcmp(env->wstr, argv[2]) != 0)
		|| env->w <= 2 || env->h <= 2 || env->w > 7000 || env->h > 7000)
		handle_exit(1, MSG_ERR_ARGS, env);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		env->fract = FRACT_JULIA;
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		env->fract = FRACT_MANDELBROT;
	else if (ft_strncmp(argv[1], "burningship", 12) == 0)
		env->fract = FRACT_BURNINGSHIP;
	else
		handle_exit(1, MSG_ERR_ARGS, env);
}
