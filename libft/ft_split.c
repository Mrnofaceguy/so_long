/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:37:04 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/07/23 13:23:20 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **out, int count)
{
	while (count--)
		free(out[count]);
	free(out);
}

static int	ft_copy_word(char **out, char *tmp, int *j, int *k)
{
	if (*k > 0)
	{
		out[*j] = ft_calloc(*k + 1, sizeof(char));
		if (!out[*j])
			return (0);
		ft_memcpy(out[*j], tmp, *k);
		(*j)++;
	}
	ft_memset(tmp, '\0', ft_strlen(tmp));
	*k = 0;
	return (1);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_init(char ***out, char **tmp, int i, int len)
{
	*out = ft_calloc(len + 1, sizeof(char *));
	if (!*out)
		return (-1);
	*tmp = ft_calloc(i + 1, sizeof(char));
	if (!*tmp)
	{
		free(*out);
		return (-1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*tmp;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	if (ft_init(&out, &tmp, ft_strlen(s), ft_count_words(s, c)) == -1)
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
	{
		if (s[i] == c && k > 0)
			if (!ft_copy_word(out, tmp, &j, &k))
				return (ft_free_all(out, j), NULL);
		if (s[i] != c)
			tmp[k++] = s[i];
	}
	if (k > 0 && !ft_copy_word(out, tmp, &j, &k))
		return (ft_free_all(out, j), NULL);
	free(tmp);
	return (out);
}
