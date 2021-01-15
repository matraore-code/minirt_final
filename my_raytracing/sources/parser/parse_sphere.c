/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:48:40 by matraore          #+#    #+#             */
/*   Updated: 2020/12/29 10:51:54 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"



int         check_sphere(t_data *g_win,char **str)
{
    int l;

    l = ft_strlen(str[0]);
    if ((fdigit_d(str[2])) || l > 2)
         return (0);
    if (ft_array_length(str) != 4)
        return (0);
    else
        return (1);

}


void			checked_value_sphere(t_data *g_win,char **arr, t_object *obj)
{
    char    **str;


    obj->type = SP;
    obj->pos[0] = parse_vector(arr[1], g_win);
    obj->size = ft_atodbl(arr[2]);
    str = ft_split(arr[3], ',');
    obj->color = parse_color(str, g_win);
	if (!lst_new_back(&(g_win->objects), obj))
		error_exit("Allocation failed for sphere", g_win);
}

extern int      parse_sphere(t_data *g_win, const char *lines)
{
    char    **array;
    t_object *object;

	    
    if (!(object = malloc(sizeof(t_object))))
        error_exit("impoosible d'allouer le sphere", g_win);
    array = ft_split(lines, ' ');
    if (!check_sphere(g_win, array))
        error_exit("ERREUR D'IMPLEMENTAION SPHERE",g_win);
	checked_value_sphere(g_win, array, object);
    return (0);
}
