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

// Integer stack definition
typedef struct s_env
{
	void	*mlxptr;
	void	*winptr;
	int		w;
	int		h;
}t_env;

// Parser
char	*parse_args(char **argv);


// Error handlers
int		exit_error(int code, char **arr, char *str);

#endif
