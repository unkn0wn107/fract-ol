/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:51:50 by agaley            #+#    #+#             */
/*   Updated: 2023/06/28 18:05:15 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include <limits.h>

# define FRACT_JULIA 1
# define FRACT_MANDELBROT 2
# define FRACT_BURNINGSHIP 3

// Integer stack definition
typedef struct s_env
{
	void	*mlxptr;
	void	*winptr;
	int		w;
	int		h;
}t_env;

// Parser
void	parse_args(char **argv, t_env *env);

// Error handlers
int		handle_exit(int code, char **arr, char *str);

#endif
