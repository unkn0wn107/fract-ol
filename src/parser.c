/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:30 by agaley            #+#    #+#             */
/*   Updated: 2023/07/17 00:57:22 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_args(char **argv, t_env *env)
{
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		env->fract = FRACT_JULIA;
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		env->fract = FRACT_MANDELBROT;
	else if (ft_strncmp(argv[1], "burningship", 12) == 0)
		env->fract = FRACT_BURNINGSHIP;
	else
		handle_exit(20, env);
}
