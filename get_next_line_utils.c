/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:04:42 by rteoh             #+#    #+#             */
/*   Updated: 2024/02/23 19:06:44 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

//returns pointer if found

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

//joins string and free the previous left_str
//returns new joined left_str

char	*ft_strjoin(char *left_str, char *buff)
{
	char	*str;
	int		i;
	int		j;
	size_t	total_len;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!buff || !left_str)
		return (NULL);
	total_len = ft_strlen(left_str) + ft_strlen(buff);
	str = (char *)malloc(total_len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (left_str[++i])
		str[i] = left_str[i];
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[total_len] = '\0';
	free(left_str);
	return (str);
}
