/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:17:44 by matraore          #+#    #+#             */
/*   Updated: 2021/01/17 16:06:06 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int         check_plan(t_data *g_win,char **str)
{
    int l;

    l = ft_strlen(str[0]);
    if (l > 2)
        return (0);
    if (ft_array_length(str) != 4)
        return (0);
    else
        return (1);

}

void			checked_value_plan(t_data *g_win,char **arr, t_object *obj)
{
    char    **str;


    obj->type = PL;
    obj->pos[0] = parse_vector(arr[1], g_win);
    obj->vector = parse_vector(arr[2], g_win);
    if (!(ft_in_range(obj->vector.x, -1, 1)))
		error_exit("ERREUR DE LA DIRECTION VECTEUR", g_win);
	if (!(ft_in_range(obj->vector.y, -1, 1)))
		error_exit("ERREUR DE LA DIRECTION VECTEUR", g_win);
	if (!(ft_in_range(obj->vector.z, -1, 1)))
		error_exit("ERREUR DE LA DIRECTION VECTEUR", g_win);
    str = ft_split(arr[3], ',');
    obj->color = parse_color(str, g_win);
	if (!lst_new_back(&(g_win->objects), obj))
		error_exit("Allocation echoue pour le plan", g_win);
}

extern int      parse_plan(t_data *g_win, const char *lines)
{
    char    **array;
    t_object *object;
	    
    if (!(object = malloc(sizeof(t_object))))
        error_exit("impoosible d'allouer le plan", g_win);
    array = ft_split(lines, ' ');
    if (!check_plan(g_win, array))
        error_exit("ERREUR D'IMPLEMENTAION PlAN",g_win);
	checked_value_plan(g_win, array, object);
    return (0);
}
