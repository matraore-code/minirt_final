#include "../../includes/math_tools.h"

/*
** Suite sur les operations basique des tuples
*/

t_tuple	multi_vect_reel(t_tuple a, double b)
{
	t_tuple	tuple;

	tuple = create_tuple(a.x * b, a.y * b, a.z * b);
	return (tuple);
}

t_tuple	div_vect_reel(t_tuple a, double b)
{
	t_tuple	tuple;

	tuple = create_tuple(a.x / b, a.y / b, a.z / b);
	return (tuple);
}


double		longueur_tuple(t_tuple a)
{
	double		l;

	l = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
	return (l);
}

t_tuple	normale_tuple(t_tuple a)
{
	t_tuple	tuple;
	double		n;

	n = 1 / longueur_tuple(a);
	tuple = create_tuple(a.x * n, a.y * n, a.z * n);
	return (tuple);
}

double		produit_scalaire(t_tuple a, t_tuple b)
{
	double		p;

	p = a.x * b.x + a.y * b.y + a.z * b.z;
	return (p);
}
