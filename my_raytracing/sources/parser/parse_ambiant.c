/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambiant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:08:03 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:09:43 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	create_ambient(t_ambiant *ambi)
{
	ambi->is_def = 0;
	ambi->ratio = 0;
	ambi->col = create_color(0, 0, 0);
}

static int         check_ambiant(t_data *g_win, char **str)
{
    int l;

    l = ft_strlen(str[0]);
    if ((fdigit_d((str[1])) || (fdigit((str[2])) || l > 1)))
        return (0);
    if (!str[1] || !str[2] || str[3])
        return (0);
    else
    {
        g_win->ambi.is_def = 1;
        return (1);
    }
}

extern int	parse_ambiant(t_data *g_win, const char *lines)
{
	char **array;
    char **str;

	array = ft_split(lines, ' ');
    if (!check_ambiant(g_win, array))
        error_exit("LA LUNMIERE AMBIANTE MAL DEFINIE", g_win);
    g_win->ambi.ratio = ft_atodbl(array[1]);
    if (g_win->ambi.ratio < 0 || g_win->ambi.ratio > 1)
        error_exit("INTERVAL DE RATIO INCORRECT", g_win);
    str = ft_split(array[2], ',');
    g_win->ambi.col = parse_color(str, g_win);
	return (0);
}
