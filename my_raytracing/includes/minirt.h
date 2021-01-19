#ifndef MINIRT_H
#define MINIRT_H

#include <stddef.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "math_tools.h"
#include "outils.h"
#include "parser.h"
#include "../librairies/get_next_line/get_next_line.h"
#include "../librairies/libft/libft.h"
#include <stdio.h>

#define yo printf("YO!\n");
#define yep printf("YEP!\n");

#define Pi 3.1415926


int initialise_img(t_data *g_win);
int render(t_data *g_win);
int initialise_win(t_data *g_win);
static int  quitte(t_data *g_win);
int				key_hook(int keycode, void *param);
void	exit_win(int keycode, t_data *data);
void	camera_prec(int keycode, t_data *data);
void	camera_suiv(int keycode, t_data *data);
int				key_hook(int keycode, void *param);
void	pixel_put(t_mlx_data g_win, int x, int y, t_color color);
t_tuple        look_at(t_cam *cam, t_tuple ray);
t_color        pixel(t_tuple_2d pix, t_data *g_win);
t_color  *get_shape(t_data *g_win);
t_color   trace_ray(t_ray, t_data *data);
t_hit hit_infini(void);
t_hit create_dist_hit(t_object *obj, t_tuple p, t_color c, double d);
t_hit   get_object_hit(t_object *obj, t_ray ray, t_data *g_win);
t_hit  get_hit_plane(t_object *plane, t_ray ray, t_data *g_win);
t_hit   get_hit_sphere(t_object *sphere, t_ray ray, t_data *g_win);
int   ombrage(t_object *object, t_light *light, t_ray ray, t_data *g_win);
t_tuple normale_sphere(t_hit hit, t_ray ray, t_data *g_win);
t_tuple	adjust_normal(t_tuple ray_dir, t_tuple norm);
t_ray	create_ray(t_tuple origin, t_tuple direction);
t_tuple	normale_plan(t_hit ray_res, t_ray ray, t_data *data);
t_tuple get_normal(t_hit hit_point, t_ray ray, t_data *g_win);
t_color     compute_light(t_hit hit_point, t_ray ray, t_light *lights,
                        t_data *g_win);
t_color     compute_lights(t_hit hit_point, t_ray ray, t_data *g_win);




#endif
