/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:56:59 by rteoh             #+#    #+#             */
/*   Updated: 2024/01/11 19:56:59 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

# endif

size_t	ft_strlen(char	*s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);
char	*ft_read(int fd, char *left_str);
char	*get_next_line(int fd);

#endif
