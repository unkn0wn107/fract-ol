/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:30 by agaley            #+#    #+#             */
/*   Updated: 2023/08/18 00:34:51 by agaley           ###   ########.fr       */
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
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		env->fract = FRACT_JULIA;
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		env->fract = FRACT_MANDELBROT;
	else if (ft_strncmp(argv[1], "bship", 12) == 0)
		env->fract = FRACT_BURNINGSHIP;
	else
		handle_exit(1, MSG_ERR_ARGS, env);
	if (argv[2] && argv[3] && argv[4]
		&& (env->fract == FRACT_MANDELBROT || env->fract == FRACT_BURNINGSHIP))
		handle_exit(1, MSG_ERR_ARGS, env);
	env->w = WIN_WIDTH;
	env->h = WIN_HEIGHT;
	parse_window_args(argv, env);
	if (env->fract == FRACT_JULIA)
		parse_fract_params(argv, env);
}

void	parse_window_args(char **argv, t_env *env)
{
	if (argv[2])
		env->w = ft_atoi(argv[2]);
	if (argv[2] && argv[3])
		env->h = ft_atoi(argv[3]);
	env->hstr = ft_itoa(env->h);
	if (!env->hstr)
		handle_exit(1, MSG_ERR_MEMORY, env);
	env->wstr = ft_itoa(env->w);
	if (!env->wstr)
		handle_exit(1, MSG_ERR_MEMORY, env);
	if ((argv[2] && argv[3] && ft_strcmp(env->hstr, argv[3]) != 0)
		|| (argv[2] && ft_strcmp(env->wstr, argv[2]) != 0)
		|| env->w <= 2 || env->h <= 2 || env->w > 7000 || env->h > 7000)
		handle_exit(1, MSG_ERR_ARGS, env);
}

void	parse_fract_params(char **argv, t_env *env)
{
	env->xinput = 285;
	env->yinput = 10;
	if (argv[4] && argv[5])
	{
		env->xinput = ft_atoi(argv[4]);
		env->yinput = ft_atoi(argv[5]);
	}
	env->xstr = ft_itoa(env->xinput);
	if (!env->xstr)
		handle_exit(1, MSG_ERR_MEMORY, env);
	env->ystr = ft_itoa(env->yinput);
	if (!env->ystr)
		handle_exit(1, MSG_ERR_MEMORY, env);
	if ((argv[4] && argv[5] && ft_strcmp(env->ystr, argv[5]) != 0)
		|| (argv[4] && ft_strcmp(env->xstr, argv[4]) != 0)
		|| env->xinput < -2000 || env->yinput < -2000
		|| env->xinput > 2000 || env->yinput > 2000)
		handle_exit(1, MSG_ERR_ARGS, env);
	env->xparam = (double)env->xinput / 1000;
	env->yparam = (double)env->yinput / 1000;
}
