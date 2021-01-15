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
