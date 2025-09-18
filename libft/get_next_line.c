/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:01:38 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/06/17 09:36:46 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char *s1, const char *s2)
{
	char	*out;
	int		len1;
	int		len2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	out = malloc(len1 + len2 + 1);
	if (!out)
		return (free(s1), NULL);
	ft_memcpy(out, s1, len1);
	ft_strcpy_from(out + len1, s2, 0);
	out[len1 + len2] = '\0';
	free(s1);
	return (out);
}

char	*ft_extract_line(const char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = ft_strlen_till_nl(stash);
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	line[i] = '\0';
	return (line);
}

char	*ft_remove_extracted_line(char *stash)
{
	char	*new_stash;
	int		i;

	i = ft_strlen_till_nl(stash);
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (NULL);
	ft_memcpy(new_stash, stash + i, ft_strlen(stash + i) + 1);
	free(stash);
	return (new_stash);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_contains_newline(stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_and_free(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	stash = ft_remove_extracted_line(stash);
	return (line);
}
