/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:17 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 17:32:57 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_exit(int error, const char *msg, t_env *env)
{
	if (env->hstr)
		free(env->hstr);
	if (env->wstr)
		free(env->wstr);
	if (env->img)
		mlx_destroy_image(env->mlxptr, env->img);
	mlx_destroy_window(env->mlxptr, env->winptr);
	mlx_destroy_display(env->mlxptr);
	free(env->mlxptr);
	if (error == 0)
		exit(0);
	else
		ft_printf(msg);
	exit(1);
}

// Gestion des erreurs
// if (code == 10)
// 	ft_printf("\nMemory allocation error");
// if (code == 11)
// 	ft_printf("\nStack doesn't exist");
// if (code == 20)
// 	ft_printf("\nArgs error : Not enough args");
// if (code == 21)
// 	ft_printf("\nArgs error : Duplicate entries");
// if (code == 22)
// 	ft_printf("\nArgs error : Not a valid integer");
// if (code == 30)
// 	ft_printf("\nStack error : Adding to empty stack");
// if (code == 31)
// 	ft_printf("\nStack error : Duplicate entries");
// if (code == 40)
// 	ft_printf("\nAlgo error : Stack is not sorted");
// if (code == 41)
// 	ft_printf("\nAlgo error : Algo not found");
