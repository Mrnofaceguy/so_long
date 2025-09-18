/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:01:01 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/06/17 09:36:15 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_print_ptr(va_list arg)
{
	void			*ptr;
	char			*out;
	int				written;

	ptr = va_arg(arg, void *);
	if (!ptr)
	{
		write(1, "(nil) ", 5);
		return (5);
	}
	write(1, "0x", 2);
	out = ft_ultoa_base((unsigned long)ptr, "0123456789abcdef");
	if (!out)
		return (2);
	written = write(1, out, ft_strlen(out));
	free(out);
	return (written + 2);
}
