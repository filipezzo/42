/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:08:38 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/01 14:59:00 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif // !BUFFER_SIZE

# ifndef MAX_FD
#  define MAX_FD 1024 
# endif // !MAX_FD

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t elmt_qtd, size_t elmt_size);
char	*join_and_free(char *s1, char *s2);
char	*ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *s);
#endif // !GET_NEXT_LINE
