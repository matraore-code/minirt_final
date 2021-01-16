#include "../includes/minirt.h"

t_tuple get_normal(t_hit hit_point, t_ray ray,t_data *g_win)
{
    if (hit_point.obj->type == SP)
        return (normale_sphere(hit_point,ray, g_win));
    return (create_tuple(0, 0, 0));
}

t_color     compute_light(t_hit hit_point, t_ray ray,
t_light *lights, t_data *g_win)
{
     t_tuple  normal;
     t_tuple  light_dir;
     double   a;
     t_ray  n_ray;
    
    (void)g_win;
    (void)ray;
    n_ray = create_ray(hit_point.pos, a_vers_b(hit_point.pos,
                lights->pos));
    if (g_win->ambi.ratio == 1)
        return (hit_point.color);
    if (ombrage(hit_point.obj, lights, n_ray, g_win))
        return (create_color(0, 0, 0));
    light_dir = a_vers_b(hit_point.pos, lights->pos);
    normal = get_normal(hit_point, ray, g_win);
    a = produit_scalaire(light_dir, normal);
    if (a < 0)
        return (create_color(0, 0, 0));
    a /= 4 * Pi * pow(distance_tuples(lights->pos, hit_point.pos), 2);
    return (multi_color_reel(multiple_colors(lights->col, hit_point.obj->color),
            fmin(a, 1)));
}

t_color     compute_lights(t_hit hit_point, t_ray ray, t_data *g_win)
{
    t_color color;
    t_list *lights;

    color = multi_color_reel(g_win->ambi.col, g_win->ambi.ratio);
    // color = multiple_colors(hit_point.obj->color, color);
    // lights = g_win->list_light;
    // while (lights)
    // {
    //     color = compare_color(color, compute_light(hit_point, ray,
    //     (t_light *)lights->content, g_win));
    //     lights = lights->next;
    // }
    return (color);
}