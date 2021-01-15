#include "../../../includes/outils.h"

t_color		create_color(double r, double g, double b)
{
	t_color		col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_color		multi_color_reel(t_color c, double a)
{
	t_color		col;

	col.r = fmin(c.r * a, 255.0);
	col.g = fmin(c.g * a, 255.0);
	col.b = fmin(c.b * a, 255.0);
	return (col);
}

