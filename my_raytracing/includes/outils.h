/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:00:57 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:40:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTILS_H
#define OUTILS_H

#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include "../librairies/get_next_line/get_next_line.h"
#include "../librairies/libft/libft.h"
#include "math_tools.h"

typedef struct		s_color
{
	double		r;
	double		g;
	double		b;
}			t_color;

typedef struct      s_ray
{
    t_tuple      ori;
    t_tuple      dir;
}                   t_ray;

typedef struct  s_resolution
{
    int         size_x;
    int         size_y;
    int         is_def;
}               t_reso;

typedef struct s_ambiant
{
    double      ratio;
    t_color     col;
    int         is_def;
}               t_ambiant;

typedef struct s_cam
{
    t_tuple    pos;
    t_tuple    dir;
    double     fov;
   t_matrice   rot_mat;
   double       distance;
}              t_cam;

typedef struct s_light
{
    t_tuple     pos;
    double      bright;
    t_color     col;
}               t_light;

typedef enum        e_objid
{
    PL,
    SP,
    TR,
    CY,
    SQ,
}                   t_objid;

typedef struct		s_object
{
	t_objid         type;
	t_tuple	        pos[3];
	t_tuple			vector;
	t_color			color;
	double			size;
	double			height;
	double			distance;
}					t_object;

typedef struct      s_hit
{
    t_object        *obj;
    t_tuple    pos;
    t_color color;
    double   distance;
}            t_hit;



typedef struct		s_mlx_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx_data;

typedef struct		s_mlxinfo
{
	void			*mlx;
	void			*mlx_win;
	t_mlx_data		mlx_data;
}					t_mlxinfo;




typedef struct        s_data
{
    t_list			*objects;
    t_list          *list_cam;
	t_cam		*camera;
    t_list          *list_light;
	t_light			*lights;
	t_reso		res;
	int         save;
	t_mlxinfo		mlx_info;
    t_ambiant       ambi;
}                       t_data;



t_color		multi_color_reel(t_color c, double a);
t_color		create_color(double r, double g, double b);
t_color		multiple_colors(t_color a, t_color b);
t_color		compare_color(t_color c, t_color a);


void error_exit(char *err, t_data *data);
void free_all(t_data *data);
void free_list(t_list *list, void (*func)(void *));
void exit_free(t_data *data);


#endif
