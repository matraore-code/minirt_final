#include "../includes/minirt.h"

int swap_d(double *d1, double *d2)
{
    double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}


t_hit   get_hit_sphere(t_object *sphere, t_ray ray, t_data *g_win)
{
    double t[3];
    double tc[2];
    double dis;
    t_tuple p;

    (void)g_win;
    p = soustraction_tuple(sphere->pos[0], ray.ori);
    tc[0] = produit_scalaire(p, ray.dir);
    dis = produit_scalaire(p, p) - pow(tc[0], 2);
    if (dis > sphere->size / 2)
        return (hit_infini());
    tc[1] = sqrt(sphere->size / 2 - dis);
    t[0] = tc[0] - tc[1];
    t[1] = tc[0] - tc[1];
    if (t[0] > t[1])
        swap_d(&t[0], &t[1]);
    if (t[0] < 0)
    {
        t[0] = t[1];
        if (t[0] < 0)
            return (hit_infini());
    }
    return ( create_dist_hit(sphere,
        addition_tuple(ray.ori, multi_tuple_reel(ray.dir, t[0])),
         sphere->color, t[0]));
}