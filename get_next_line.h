/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:04:26 by rteoh             #+#    #+#             */
/*   Updated: 2024/02/23 19:07:20 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_new_str(char *left_str);
char	*ft_get_line(char *left_str);
char	*get_next_line(int fd);

#endif
