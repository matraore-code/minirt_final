/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:45:49 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:33:13 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"

int         ft_array_length(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
        i++;
    return (i);
}

int         fdigit_d(char *str)
{
    int i;
    int j;

     i = 0;
     j = 0;
     while (str[i] != '\0')
     {
        if (str[i] == 46)
            i++;
        if (!ft_isdigit(str[i]))
            j++;
        i++;
     }
     return (j);
}

int         fdigit(char *str)
{
    int i;
    int j;

     i = 0;
     j = 0;
     while (str[i] != '\0')
     {
        if (str[i] == 44)
            i++;
        if (!ft_isdigit(str[i]))
            j++;
        i++;
     }
     return (j);
}

t_color     parse_color(char **array, t_data *g_win)
{
    t_color    color;

    if (fdigit((array[1])) || fdigit((array[0])) ||
                        fdigit((array[2])))
        error_exit("Erreur dans les valeurs de la couleur", g_win);
    color.r = ft_atodbl(array[0]);
    color.g = ft_atodbl(array[1]);
    color.b = ft_atodbl(array[2]);
    if (color.r > 255 || color.g > 255 ||
            color.b > 255 || color.r < 0 ||
            color.g < 0 || color.b < 0)
                error_exit("INTERVAL DE COULEUR INCORRECT", g_win);
    
    
    return (color);
}
