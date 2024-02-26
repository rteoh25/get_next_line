/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:04:32 by rteoh             #+#    #+#             */
/*   Updated: 2024/02/23 19:08:02 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//the function is to make a new left_str removing the line
//we have already outputted and freeing the previous line

char	*ft_get_new_str(char *left_str)
{
	char	*buff;
	size_t	i;
	size_t	j;

	i = 0;
	while (left_str[i] != '\n' && left_str[i])
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	buff = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i) + 1);
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		buff[j++] = left_str[i++];
	buff[j] = '\0';
	free (left_str);
	return (buff);
}

//the function is to malloc a new string for a line, anything before '\n'
//there are only 3 outcomes, 1) end of file,
//2) newline then end of file, 3) newline not end of file
//our first condition if (!left_str[i]) checks whether its the end of the file.
//i+2 for null terminator '\0' and new line. which handles situation 2 and 3
//situation 2 and 3 doesnt really make a difference
//since we would always null terminate the output even if
//its the end of the file or its a newline

char	*ft_get_line(char *left_str)
{
	char	*buff;
	int		i;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] != '\n' && left_str[i])
		i++;
	buff = (char *)malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (NULL);
	i = 0;
	while (left_str[i] != '\n' && left_str[i])
	{
		buff[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		buff[i] = left_str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

//reading the file in chunks until a newline char '\n'
//or the end of the file is reached
//BUFFER_SIZE is the size of the chunks the function reads each time
//each time the function reads, it is joining the new data
//with the previously read data.
//putting that data in buffer temporarily, and joining it into left_str
//freeing buffer after it is done and return left_str

char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0 && !ft_strchr(left_str, '\n'))
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

//IMPORTANT: static variable
//static variable is a variable that has a limited scope and it is
//able to retain data even after it is manipulated by functions.
//in simple terms, static variable is a box that will remember the
//informtion in the box even after a function puts in new information.
//difference between global variable and static variable is the scope of
//its accessibility.

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	left_str = ft_read(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_get_new_str(left_str);
	return (line);
}

/*
int	main(void)
{
	char	*line;
	int		fd1;
	int		i;

	fd1 = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		i++;
	}
}
*/