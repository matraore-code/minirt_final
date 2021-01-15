/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:17:11 by matraore          #+#    #+#             */
/*   Updated: 2020/12/22 16:24:56 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

double      ft_max(double a, double b)
{
    if (a < b)
        return (b);
    else
        return (a);

}

double      ft_min(double a, double b)
{
    if (a < b)
        return (a);
    else
        return (b);
    
}

double      ft_square(double a)
{
    return (a * a);
}

int          ft_in_range(double d, double d_min, double d_max)
{
    if (d_min <= d && d <= d_max)
        return (1);
    return (0);
}
