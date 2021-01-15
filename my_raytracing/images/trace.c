#include "../includes/minirt.h"


t_hit   get_object_hit(t_object *obj, t_ray ray, t_data *g_win)
{
    if (obj->type == PL)
        return (get_hit_plane(obj, ray, g_win));
    if (obj->type == SP)
        return (get_hit_sphere(obj, ray, g_win));
}

t_hit  hit_object(t_ray ray, t_data *g_win)
{
    t_list *list_obj;
    t_object   *near_obj;
    t_hit  hit;
    t_hit  near_hit;
    double  d;

    d = INFINITY;
    near_obj =  NULL;
    list_obj = g_win->objects;
    while (list_obj)
    {
        hit = get_object_hit((t_object *)list_obj, ray, g_win);
        if (hit.distance < d)
        {
            near_obj = (t_object *)list_obj->content;
            d = near_hit.distance;
            near_hit = hit;
        }
        list_obj = list_obj->next;
    }
    if (!near_obj)
        return (hit_infini());
    return (near_hit);
}

t_color   trace_ray(t_ray ray, t_data *g_win)
{
    t_hit hit;

    hit = hit_object(ray, g_win);
    if (hit.distance ==INFINITY)
        return (create_color(0, 0, 0));
    return (trace_light(hit, ray, g_win));
    
}