/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:39:40 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/09 19:39:40 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

size_t	ft_strlens(const char *s);
char	*ft_callocs(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoins(char *s1, char *s2, size_t len);
#endif