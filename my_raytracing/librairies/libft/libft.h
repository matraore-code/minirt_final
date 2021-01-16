/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:54:19 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 10:48:50 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_list	t_list;

struct	s_list
{
	void	*content;
	t_list	*next;
	t_list	*prev;
};

int				ft_isalnum(int c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalpha(int ch);
int				ft_isascii(int i);
int				ft_isdigit(int c);
int				ft_isprint(int i);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void            ft_memdel(void **ap);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c);
void			ft_putendl_fd(char *s);
void			ft_putnbr_fd(int n);
void			ft_putstr_fd(char *s);
char			**ft_split(char const *s1, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
void			ft_strdel(char **as);
double			ft_atodbl(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str1, const char *str2, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
int				ft_ischarset(const char *charset, int c);

#endif
