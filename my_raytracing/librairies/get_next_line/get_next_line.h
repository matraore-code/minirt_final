/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:14:59 by matraore          #+#    #+#             */
/*   Updated: 2020/12/22 18:12:56 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# define BUFFER_SIZE 1000

size_t	ft_strlenl(const char *str);
char	*ft_strdupl(const char *str);
char	*ft_strchrl(const char *s, int c);
char	*ft_strjoinl(char *s1, char const *s2);
char	*ft_substrl(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);


#endif
