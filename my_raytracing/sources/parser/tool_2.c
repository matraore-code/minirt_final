/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:29:18 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:33:25 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int         fdigit_m(char *str)
{
    int i;
    int j;

     i = 0;
     j = 0;
     while (str[i] != '\0')
     {
        if (str[i] == 45 || str[i] == 46)
            i++;
        if (!ft_isdigit(str[i]))
            j++;
        i++;
     }
     return (j);
}

t_tuple				parse_vector(char *str, t_data *d)
{
	char		**array;
    t_tuple     vect;

	array = ft_split(str, ',');
	if (ft_array_length(array) != 3 ||
            fdigit_m(array[0]) || fdigit_m(array[1]) || fdigit_m(array[2]))
        error_exit("ERREUR DE PARSING VECTEURS",d);
	else
	{
		vect.x = ft_atodbl(array[0]);
		vect.y = ft_atodbl(array[1]);
		vect.z = ft_atodbl(array[2]);
	}
	return (vect);
}


