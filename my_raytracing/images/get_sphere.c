#include "../includes/minirt.h"

int swap_d(double *d1, double *d2)
{
    double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
    return (0);
}

t_tuple normale_sphere(t_hit hit, t_ray ray, t_data *g_win)
{
        return (a_vers_b(hit.obj->pos[0], hit.pos));
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
    printf("[dis : %f] %f\n", dis, sphere->size);
    // if (dis > sphere->size / 2)
    // {
    //     return (hit_infini());
    // }
    tc[1] = sqrt(sphere->size / 2 - dis);
    t[0] = tc[0] - tc[1];
    t[1] = tc[0] + tc[1];
    if (t[0] > t[1])
        swap_d(&t[0], &t[1]);
    if (t[0] < 0)
    {
        t[0] = t[1];
        if (t[0] < 0)
            return (hit_infini());
    }
    return (create_dist_hit(sphere,
        addition_tuple(ray.ori, multi_tuple_reel(ray.dir, t[0])),
         sphere->color, t[0]));
}

t_ray_res	obj_dist_pl(t_object *plane, t_ray ray, t_data *data)
{
	double	denom;
	double	t;

	(void)data;
	denom = vec_dot_prod(plane->vector, ray.direction);
	t = (vec_dot_prod(vec_sub(plane->pos[0], ray.origin), plane->vector) /
		denom);
	if (t < 0)
		return (ray_res_inf());
	return (ray_res_dist_new(plane, vec_add(ray.origin,
					vec_multi(ray.direction, t)), plane->color, t));
}