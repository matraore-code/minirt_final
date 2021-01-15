#include "../includes/minirt.h"

t_hit create_dist_hit(t_object *obj, t_tuple p, t_color c, double d)
{
    t_hit hit;

    hit.obj = obj;
    hit.color = c;
    hit.distance = d;
    hit.pos = p;
    return (hit);
}


t_hit hit_infini(void)
{
    t_tuple tuple;
    t_color color;

    tuple = create_tuple(0, 0, 0);
    color = create_color(0, 0, 0);
    return (create_dist_hit(NULL, tuple, color, INFINITY));
}