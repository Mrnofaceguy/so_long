/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:03:49 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/07/01 14:04:37 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <limits.h> 

static int	ft_parse(va_list *args, char type)
{
	if (type == 'c')
		return (ft_print_char(*args));
	if (type == 's')
		return (ft_print_str(*args));
	if (type == 'p')
		return (ft_print_ptr(*args));
	if (type == 'd' || type == 'i')
		return (ft_print_int(*args));
	if (type == 'u')
		return (ft_print_uni(*args));
	if (type == 'x')
		return (ft_print_base(*args, "0123456789abcdef"));
	if (type == 'X')
		return (ft_print_base(*args, "0123456789ABCDEF"));
	return (0);
}

int	handle_format(va_list *args, const char *format, int *i)
{
	int	ret;

	(*i)++;
	if (format[*i] == '%')
	{
		write(1, "%", 1);
		(*i)++;
		return (1);
	}
	ret = ft_parse(args, format[*i]);
	if (ret == -1)
	{
		write(1, "%", 1);
		write(1, &format[*i], 1);
		ret = 2;
	}
	(*i)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		written;

	va_start(args, format);
	i = 0;
	written = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			written += handle_format(&args, format, &i);
		else
		{
			write(1, &format[i], 1);
			written++;
			i++;
		}
	}
	va_end(args);
	return (written);
}
