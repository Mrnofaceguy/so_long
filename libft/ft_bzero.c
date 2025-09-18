/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:43:50 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/18 10:47:22 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		++i;
	}
	return (p);
}

void	*ft_bzero(void *ptr, size_t len)
{
	ft_memset (ptr, 0, len);
	return (ptr);
}
