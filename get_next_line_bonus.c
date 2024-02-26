/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:44 by rteoh             #+#    #+#             */
/*   Updated: 2024/01/11 15:30:44 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_new_left_str(char *left_str)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free (left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(left_str) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free (left_str);
	return (str);
}

char	*ft_get_line(char *left_str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!left_str[i])
		return (NULL);
	i = ft_strlen(left_str);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (left_str[i] != '\0' && left_str[i] != '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

//so we put it in this function to read the file
//looking for the end of the file or until a new line.

char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

//what im doing is declaring an array of array to
//keep multiple files information

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[3000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/