/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:39:40 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/23 11:23:43 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h> 

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

void	*ft_calloc(size_t num, size_t size)
{
	void	*out;

	if (num != 0 && size > (size_t) - 1 / num)
		return (NULL);
	out = malloc(num * size);
	if (!out)
		return (NULL);
	ft_memset(out, 0, num * size);
	return (out);
}
