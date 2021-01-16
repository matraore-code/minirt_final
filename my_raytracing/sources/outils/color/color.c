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

t_color		multiple_colors(t_color a, t_color b)
{
	t_color		col;

	col.r = a.r * b.r / 255.0;
	col.g = a.g * b.g / 255.0;
	col.b = a.b * b.b / 255.0;
	return (col);
}

t_color		compare_color(t_color c, t_color a)
{
	t_color		col;

	col.r = fmax(c.r, a.r);
	col.g = fmax(c.g, a.g);
	col.b = fmax(c.b, a.b);
	return (col);
}

