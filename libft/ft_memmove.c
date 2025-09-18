/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:59 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/15 13:16:18 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || len == 0)
		return (dest);
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			++i;
		}
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dest);
}
