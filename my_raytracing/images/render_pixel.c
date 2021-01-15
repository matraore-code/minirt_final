#include "../includes/minirt.h"
#define Pi 3.1415926


void	pixel_put(t_mlx_data g_win, int x, int y, t_color color)
{
	char *dst;
    int  color_int;

	dst = g_win.addr + (y * g_win.line_length + x * (g_win.bits_per_pixel / 8));
    color_int = ((int)color.r << 16 | (int)color.g << 8 | (int)color.b);
	*(unsigned int*)dst = color_int;
}

t_tuple        look_at(t_cam *cam, t_tuple ray)
{
        t_matrice mat;
        t_tuple  inverse_dir;
        t_tuple  unit;
        t_tuple droit;
        t_tuple haut;

    inverse_dir = multi_tuple_reel(cam->dir, -1);
    unit = create_tuple(0, 1, 0);
    droit = produit_vectoriel(normale_tuple(unit), inverse_dir);
    haut = produit_vectoriel(inverse_dir, droit);
    mat.avant = inverse_dir;
    mat.droit = droit;
    mat.haut = haut;
    return (multi_matrice_tuple(ray, mat));
}

t_color        pixel(t_tuple_2d pix, t_data *g_win)
{
        t_ray   ray;
        t_cam   *cam;
        double   fov_h;
        t_color cast;
    
        cam = g_win->camera;
        fov_h = tan(cam->fov / 2 * (Pi / 180));
        ray.ori.x = (2 * ((pix.x + 0.5) / g_win->res.size_x - 1)* fov_h);
        ray.ori.y = (1 - (2 * ((pix.y + 0.5) / g_win->res.size_y)* fov_h));
        ray.ori.z = -1;
        ray.ori = look_at(cam, ray.ori);
        if (g_win->res.size_x > g_win->res.size_y)
		    ray.ori.x *= g_win->res.size_x / (double)g_win->res.size_y;
	    else
		ray.ori.y *= g_win->res.size_y / (double)g_win->res.size_x;
        ray.dir = normale_tuple(ray.ori);
        ray.ori = g_win->camera->pos;
        cast = trace_ray(ray, g_win);
        return (cast);
}

t_color  *get_shape(t_data *g_win)
{
    t_color  *shape;
    int x;
    int y;

    shape = tools_malloc(sizeof(t_color) * g_win->res.size_x * g_win->res.size_y);
    x = 0;
    while (x < g_win->res.size_x)
    {
        y = 0;
        while (y < g_win->res.size_y)
        {
            shape[x * g_win->res.size_y + y] = pixel((t_tuple_2d){x, y}, g_win);
            y++;
        }
        x++;
    }
    return (shape);
}