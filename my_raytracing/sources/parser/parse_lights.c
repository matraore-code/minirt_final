/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:22:04 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:32:19 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"

t_light		*create_light(t_data *g_win)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		error_exit("ERREUR CREATION de lumiere", g_win);
	light->pos = create_tuple(0, 0, 0);
	light->bright = 0;
	light->col = create_color(0, 0, 0);
	return (light);
}

int         check_light(t_data *g_win,char **str)
{
    int l;

    l = ft_strlen(str[0]);
    if ((fdigit_d(str[2])) || l > 1)
         return (0);
    if (ft_array_length(str) != 4)
        return (0);
    else
        return (1);

}



void			checked_value_light(char **array, t_light *light, t_data *g_win)
{
    char    **str;

	if (!(ft_in_range(light->bright = ft_atodbl(array[2]), 0, 1)))
			error_exit("ERREUR BRIGTHNESS", g_win);
	light->pos = parse_vector(array[1], g_win);
    str = ft_split(array[3], ',');
    light->col = parse_color(str, g_win);
}

extern int      parse_light(t_data *g_win, const char *lines)
{
    char    **array;
	 t_light	*light;
    array = ft_split(lines, ' ');
	light = create_light(g_win);
    if (!check_light(g_win, array))
        error_exit("ERREUR D'IMPLEMENTAION LUMIERE", g_win);
	checked_value_light(array, light, g_win);
	if (!lst_new_back(&(g_win->list_light), light))
		error_exit("Allocation failed for light", g_win);
    return (0);
}
