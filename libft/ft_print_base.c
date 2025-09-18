/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:46:29 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/06/17 09:35:53 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_ulonglen(unsigned long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long num, char *base)
{
	int		base_len;
	int		len;
	char	*out;

	base_len = ft_strlen(base);
	len = ft_ulonglen(num, base_len);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	out[len] = '\0';
	while (len-- > 0)
	{
		out[len] = base[num % base_len];
		num /= base_len;
	}
	return (out);
}

int	ft_print_base_from_ulong(unsigned long num, char *base)
{
	char	*out;
	int		written;

	if (ft_strlen(base) < 2)
		return (0);
	if (num == 0)
		return (write(1, "0", 1));
	out = ft_ultoa_base(num, base);
	if (!out)
		return (0);
	written = write(1, out, ft_strlen(out));
	free(out);
	return (written);
}

int	ft_print_base(va_list arg, char *base)
{
	unsigned int	num;
	char			*out;
	int				written;

	num = va_arg(arg, unsigned int);
	if (ft_strlen(base) < 2)
		return (0);
	if (num == 0)
		return (write(1, "0", 1));
	out = ft_ultoa_base(num, base);
	if (!out)
		return (0);
	written = write(1, out, ft_strlen(out));
	free(out);
	return (written);
}
