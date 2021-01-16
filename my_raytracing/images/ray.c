#include "../includes/minirt.h"


t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray ray;

	ray.ori = origin;
	ray.dir = direction;
	return (ray);
}

int   ombrage(t_object *object, t_light *light, t_ray ray, t_data *g_win)
{
    t_list *objects;
    t_hit    hit_point;
    double d;

    object = g_win->objects->content;
    d = distance_tuples(ray.ori, light->pos);
    while (object)
    {
        if (objects->content != object)
        {
            hit_point = get_object_hit((t_object *)objects->content, ray, g_win);
            if (hit_point.distance < d)
                return(1);
        }
        objects = objects->next;
    }
    return (0);
}