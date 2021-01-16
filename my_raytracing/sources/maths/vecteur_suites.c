/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_suites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:47:33 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 08:53:20 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math_tools.h"

/*
** Suite et fin des operations sur les tuples.
*/

t_tuple	produit_vectoriel(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple = create_tuple((a.y * b.z) - (a.z * b.y),
			(a.z * b.x) - (a.x * b.z),
			(a.x * b.y) - (a.y * b.x));
	return (tuple);
}

t_tuple	a_vers_b(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple = normale_tuple(soustraction_tuple(b, a));
	return (tuple);
}
