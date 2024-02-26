/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:25:40 by rteoh             #+#    #+#             */
/*   Updated: 2024/01/11 15:25:40 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * 1);
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(buff)
				+ ft_strlen(left_str) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (left_str[++i])
		str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(buff) + ft_strlen(left_str)] = '\0';
	free(left_str);
	return (str);
}
