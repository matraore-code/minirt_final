/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:52:55 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 10:26:33 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"
#include "../../librairies/minilibx/mlx.h"
#include <stdlib.h>

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

int check_resolution(t_data *g_win,char **str)
{
    int l;

    l = ft_strlen(str[0]);
    if (fdigit((str[1])) || fdigit((str[2])) || l > 1)
        return (0);
    if (!str[1] || !str[2] || str[3])
        return (0);
    else
    {
        g_win->res.is_def = 1;
        return (1);
    }
}

int	parse_resolution(t_data *g_win, const char *lines)
{
	char **array;
    int  x_max;
    int  y_max;

	array = ft_split(lines, ' ');
    if (!check_resolution(g_win, array))
        error_exit("RESOLUTION MAL DEFINIE", g_win);
    g_win->res.size_x = ft_atoi(array[1]);
    g_win->res.size_y = ft_atoi(array[2]);
    mlx_get_screen_size(g_win->mlx_info.mlx, &x_max, &y_max);
    if (g_win->res.size_x > x_max)
            g_win->res.size_x = x_max;
    if (g_win->res.size_y > y_max)
            g_win->res.size_y = y_max;
    if ((g_win->res.size_x < 0) || (g_win->res.size_y < 0))
           error_exit("Taille trop petite", g_win);
	return (0);
}