/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:17 by agaley            #+#    #+#             */
/*   Updated: 2023/07/16 20:27:55 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_exit(int code, char **arr, char *str)
{
	int	i;

	(void)code;
	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
	if (str)
		free(str);
	if (code == 0)
		exit(0);
	if (code == 20)
		ft_printf("Args error\n");
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
