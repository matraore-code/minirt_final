/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:16:26 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 08:42:17 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math_tools.h"

/*
** Operations basiques sur les tuples.
*/

t_tuple		create_tuple(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	return (tuple);
}

t_tuple		addition_tuple(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple = create_tuple(a.x + b.x, a.y + b.y, a.z + b.z);
	return (tuple);
}

t_tuple	soustraction_tuple(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple = create_tuple(a.x - b.x, a.y - b.y, a.z - b.z);
	return (tuple);
}

t_tuple	produit_tuple(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple = create_tuple(a.x * b.x, a.y * b.y, a.z * b.z);
	return (tuple);
}

double		distance_tuples(t_tuple a, t_tuple b)
{
	double		distance;

	distance = sqrt(pow(a.x - b.x, 2) +
			pow(a.y - b.y, 2) +
			pow(a.z - b.z, 2));
	return (distance);
}
