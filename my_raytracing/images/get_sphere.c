#include "../includes/minirt.h"

void swap_d(double *d1, double *d2)
{
    double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

static double	tuple_angle(t_tuple vec1, t_tuple vec2)
{
	double	res;

	res = produit_scalaire(vec1, vec2);
	res /= longueur_tuple(vec1) * longueur_tuple(vec2);
	res = acos(res);
	return (res);
}

t_tuple	adjust_normal(t_tuple ray, t_tuple norm)
{
	if (tuple_angle(norm, ray) < Pi)
		return (multi_tuple_reel(norm, -1));
	return (norm);
}

t_tuple normale_sphere(t_hit hit, t_ray ray, t_data *g_win)
{
        t_tuple tuple;
    
        tuple = a_vers_b(hit.obj->pos[0], hit.pos);
        return (adjust_normal(ray.dir, tuple));
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
    {
        return (hit_infini());
    }
    tc[1] = sqrt(sphere->size / 2  - dis);
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
<<<<<<< HEAD
    return (create_dist_hit(sphere, addition_tuple(ray.ori, multi_tuple_reel(ray.dir, t[0])), sphere->color, t[0]));
}

 //gcc minirt.c sources/maths/*.c sources/outils/color/*.c sources/outils/error_print/*.c sources/parser/*.c librairies/libft/*.c librairies/get_next_line/*.c sources/outils/tools/*.c images/*.c -lmlx -framework OpenGL -framework AppKit libmlx.dylib -fsanitize=address
=======
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
>>>>>>> 4a76dbbbbf05f509dba51bdbc167378e5c3932d0
