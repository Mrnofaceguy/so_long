/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:35:18 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/15 11:08:46 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_number(char *str, int n, int len)
{
	unsigned int	num;

	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)n;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*out;

	len = ft_intlen(n);
	out = (char *)ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_fill_number(out, n, len);
	return (out);
}
