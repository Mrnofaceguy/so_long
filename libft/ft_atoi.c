/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 07:54:34 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/04/18 10:46:09 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_parse_num(char *str)
{
	int	out;

	out = 0;
	while (*str >= '0' && *str <= '9')
	{
		out = out * 10 + (*str - '0');
		++str;
	}
	return (out);
}

int	ft_atoi(char *str)
{
	int	temp;

	temp = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		++str;
	}
	if (*str == '-')
	{
		temp *= -1;
		++str;
	}
	else if (*str == '+')
	{
		++str;
	}
	if (*str >= '0' && *str <= '9')
	{
		return (ft_parse_num((char *)str) * temp);
	}
	return (0);
}
