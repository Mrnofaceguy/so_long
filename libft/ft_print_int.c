/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:57:54 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/06/17 09:36:07 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(va_list arg)
{
	int	num;
	int	out;

	num = va_arg(arg, int);
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		write (1, "-", 1);
		out = ft_print_base_from_ulong((unsigned long) -num, "0123456789");
		return (1 + out);
	}
	return (ft_print_base_from_ulong((unsigned long) num, "0123456789"));
}
