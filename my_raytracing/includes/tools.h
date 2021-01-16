/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 05:38:53 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:51:47 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../librairies/libft/libft.h"
# define TRUE 1
# define FALSE 0
# define EPSILON 0.00001






int			g_global_memory;
double		square(double x);
double		degre_to_radian(double angle);
void		tools_memory_init (void);
void		*tools_malloc(int alloc);
void		tools_free(void **ptr, int alloc);
void		tools_memory_check_at_end_of_app(void);
int			equal(double n1, double n2);
double      ft_max(double a, double b);
double      ft_min(double a, double b);
double      ft_square(double a);
int          ft_in_range(double d, double d_min, double d_max);

t_list	*lst_new(void *content);
t_list	*lst_new_back(t_list **node, void *content);
void	lst_new_front(t_list **node, void *content);
void	lst_remove(t_list *node, void (*free_func)(void *));
#endif
