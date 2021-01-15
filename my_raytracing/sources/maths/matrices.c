#include "../../includes/math_tools.h"

/*
** Operations sur les matrices
*/

t_matrice	create_matrice(t_tuple a)
{
	t_matrice	matrice;
	t_tuple		tuple;

	tuple = create_tuple(0, 1, 0);
	matrice.avant = multi_tuple_reel(a, -1);
	matrice.droit = produit_vectoriel(normale_tuple(tuple),
			matrice.avant);
	matrice.haut = produit_vectoriel(matrice.avant, matrice.droit);
	return (matrice);
}

t_matrice	normal_matrice(t_matrice mat)
{
	t_matrice	matrice;

	matrice.avant = normale_tuple(mat.avant);
	matrice.droit = normale_tuple(mat.droit);
	matrice.haut = normale_tuple(mat.haut);
	return (matrice);
}

t_matrice	multiplication_matrice_reel(t_matrice mat, double a)
{
	t_matrice	matrice;

	matrice.avant = multi_tuple_reel(mat.avant, a);
	matrice.droit = multi_tuple_reel(mat.droit, a);
	matrice.haut = multi_tuple_reel(mat.haut, a);
	return (matrice);
}

t_matrice	multiplication_matrice(t_matrice a, t_matrice b)
{
	t_matrice	 matrice;

	matrice.droit.x = a.droit.x * b.droit.x + a.haut.x * b.droit.y + a.avant.x *
		b.droit.z;
	matrice.droit.y = a.droit.y * b.droit.x + a.haut.y * b.droit.y + a.avant.y *
		b.droit.z;
	matrice.droit.z = a.droit.z * b.droit.x + a.haut.z * b.droit.y + a.avant.z *
		b.droit.z;
	matrice.haut.x = a.droit.x * b.haut.x + a.haut.x * b.haut.y + a.avant.x * b.haut.z;
	matrice.haut.y = a.droit.y * b.haut.x + a.haut.y * b.haut.y + a.avant.y * b.haut.z;
	matrice.haut.z = a.droit.z * b.haut.x + a.haut.z * b.haut.y + a.avant.z * b.haut.z;
	matrice.avant.x = a.droit.x * b.avant.x + a.haut.x * b.avant.y +
		a.avant.x * b.avant.z;
	matrice.avant.y = a.droit.y * b.avant.x + a.haut.x * b.avant.y +
		a.avant.y * b.avant.z;
	matrice.avant.z = a.droit.y * b.avant.x + a.haut.x * b.avant.y +
		a.avant.z * b.avant.z;
	return (matrice);
}

t_tuple		multi_matrice_tuple(t_tuple a, t_matrice mat)
{
	t_tuple		resultat;

	resultat.x = a.x * mat.droit.x + a.y * mat.haut.x + a.z * mat.avant.x;
	resultat.y = a.x * mat.droit.y + a.y * mat.haut.y + a.z * mat.avant.y;
	resultat.z = a.x * mat.droit.z + a.y * mat.haut.z + a.z * mat.avant.z;
	return (resultat);
}
