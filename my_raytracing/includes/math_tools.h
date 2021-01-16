#ifndef MATHS_H
#define MATH_TOOLS_H

#include <stddef.h>
#include <math.h>
#include <stdlib.h>

/*
** TUPLES ET MATRICES
*/

typedef struct		s_tuple_2d
{
	double		x;
	double		y;
}			t_tuple_2d;

typedef struct		s_tuple
{
	double		x;
	double		y;
	double		z;
}			t_tuple;


typedef struct		s_matrice
{
	t_tuple	avant;
	t_tuple	droit;
	t_tuple	haut;
	t_tuple	translation;
}			t_matrice;

t_tuple		create_tuple(double x, double y, double z);
t_tuple		addition_tuple(t_tuple a, t_tuple b);
t_tuple		soustraction_tuple(t_tuple a, t_tuple b);
t_tuple		produit_tuple(t_tuple a, t_tuple b);
double			distance_tuples(t_tuple a, t_tuple b);
t_tuple		multi_tuple_reel(t_tuple a, double b);
t_tuple		div_vect_reel(t_tuple a, double b);
double			longueur_tuple(t_tuple a);
t_tuple		normale_tuple(t_tuple a);
double			produit_scalaire(t_tuple a, t_tuple b);
t_tuple	produit_vectoriel(t_tuple a, t_tuple b);
t_tuple	a_vers_b(t_tuple a, t_tuple b);
t_matrice	create_matrice(t_tuple a);
t_matrice	multiplication_matrice(t_matrice a, t_matrice b);
t_matrice	multiplication_matrice_reel(t_matrice mat, double a);
t_matrice	normal_matrice(t_matrice mat);
t_tuple		multi_matrice_tuple(t_tuple a, t_matrice mat);

#endif
