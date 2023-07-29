/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:18:12 by agaley            #+#    #+#             */
/*   Updated: 2023/07/29 02:41:38 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	report_result(int pass, char *message, int suite_failed)
{
	if (pass)
	{
		(void)suite_failed;
		ft_printf("OK : ", message);
		return (0);
	}
	else
	{
		suite_failed = 1;
		ft_printf("!!!KO : ", message);
		return (1);
	}
}
