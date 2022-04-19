/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:23:43 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/19 04:27:59 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	ft_bzero_gnl(void *s, size_t n);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line(int fd);

#endif
