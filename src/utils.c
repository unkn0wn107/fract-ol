/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:52:18 by agaley            #+#    #+#             */
/*   Updated: 2023/07/09 01:03:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Compares the first n characters of strings s1 and s2 and frees s1.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of characters to compare.
 *
 * @returns The difference between the first characters (as unsigned char)
 * that differ in s1 and s2.
 * 0 if the first n characters are equal or if n is equal to zero.
 */
int	ft_strncmp_free1(char *s1, char *s2, size_t n)
{
	int	r;

	r = ft_strncmp(s1, s2, n);
	if (s1)
		free(s1);
	return (r);
}
