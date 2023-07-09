/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:30 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 23:22:24 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*parse_args(char **argv)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		exit_error(1, NULL, NULL);
	str[0] = '\0';
	i = 1;
	while (argv[i])
	{
		str = ft_strpush(str, " ");
		if (!str)
			exit_error(1, NULL, NULL);
		str = ft_strpush(str, argv[i++]);
		if (!str)
			exit_error(1, NULL, NULL);
	}
	return (str);
}
