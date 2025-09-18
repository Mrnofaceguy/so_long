/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:48:29 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/06/17 09:36:22 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_print_str(va_list arg)
{
	char	*content;

	content = va_arg (arg, char *);
	if (!content)
		content = "(null)";
	return (write(1, content, ft_strlen(content)));
}
