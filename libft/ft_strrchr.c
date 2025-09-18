/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:37:06 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/18 11:12:56 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		++str;
		++i;
	}
	return (i);
}

char	*ft_strrchr(const char *dest, int c)
{
	int	i;

	i = ft_strlen(dest);
	while (i >= 0)
	{
		if (dest[i] == (char)c)
			return ((char *)&dest[i]);
		--i;
	}
	return (NULL);
}
