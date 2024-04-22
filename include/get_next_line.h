/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:04:52 by szalazar          #+#    #+#             */
/*   Updated: 2024/02/28 13:42:25 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_text(int fd, char *static_buffer);
char	*ft_line(char *static_buffer);
char	*ft_new_line(char *static_buffer);

int		ft_strlen(char *str);
char	*ft_gnl_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
