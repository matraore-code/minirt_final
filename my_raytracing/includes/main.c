#include "math_tools.h"
#include <stdio.h>


int main()
{
	t_tuple a;
	t_tuple b;
	double i = 4;
	t_tuple c;
	a = create_tuple(1, 2 ,3);
	printf("%2.f %2.f %2.f\n", a.x, a.y, a.z);
	a = addition_tuple(a, a);	
	printf("%2.f %2.f %2.f \n", a.x, a.y, a.z);	
	a = produit_tuple(a, a);
	printf("%2.f %2.f %2.f\n", a.x, a.y, a.z);
	i = distance_tuples(a, create_tuple(5,3,4));
	printf("%2.f\n", i);
	a = soustraction_tuple(a, a);
	printf("%2.f %2.f %2.f\n", a.x, a.y, a.z);
	a = produit_vectoriel(create_tuple(1,2,3),create_tuple(2,3,4));
	printf("%2.f %2.f %2.f\n", a.x, a.y, a.z);
	i = produit_scalaire(create_tuple(1,2,3),create_tuple(2,3,4));
	printf("%2.f\n",i);
	return (0);
}
