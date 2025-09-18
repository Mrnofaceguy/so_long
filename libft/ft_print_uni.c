/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:26:55 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/06/17 09:35:36 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_print_uni(va_list arg)
{
	unsigned int	num;
	char			*out;
	int				written;

	num = va_arg(arg, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	out = ft_ultoa_base((unsigned long) num, "0123456789");
	if (!out)
		return (0);
	written = write(1, out, ft_strlen(out));
	free(out);
	return (written);
}
