/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:06:50 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/15 13:45:15 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *tab, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*out;

	if (!tab || !f)
		return (NULL);
	i = 0;
	out = ft_calloc(ft_strlen(tab) + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (tab[i])
	{
		out[i] = f(i, tab[i]);
		++i;
	}
	out[i] = '\0';
	return (out);
}
