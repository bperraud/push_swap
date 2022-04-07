/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:32:14 by bperraud          #+#    #+#             */
/*   Updated: 2022/02/06 15:32:14 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if BUFFER_SIZE < -1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif
# if BUFFER_SIZE > 2147483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

# define OPEN_MAX 256

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*true_gnl(int fd);
char	*true_gnl_2(long ret, char *line, char *buff, char *temp);
void	*ft_memchr(const void *s, int c, long n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, const char *src, long n);
char	**ft_split(char const *s, const char c);
size_t	ft_strlen(const char *s);
char	*end_of_line(char *line, char *buff);

#endif
