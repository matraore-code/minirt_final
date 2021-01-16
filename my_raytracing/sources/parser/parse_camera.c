/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:48:40 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 11:24:10 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"

t_cam		*create_cam(t_data *g_win)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		error_exit("ERREUR CREATION CAMERA", g_win);
	cam->pos = create_tuple(0, 0, 0);
	cam->dir = create_tuple(0, 0, 0);
	cam->fov = 0;
	cam->rot_mat = create_matrice(cam->dir);
	cam->distance = 0;
	return (cam);
}



int         check_camera(t_data *g_win,char **str)
{
    int l;

    l = ft_strlen(str[0]);
    if ((fdigit_d(str[3])) || l > 1)
         return (0);
    if (ft_array_length(str) != 4)
        return (0);
    else
        return (1);

}



void			checked_value_cam(char **array, t_cam *cam, t_data *d)
{
	if (!(ft_in_range(cam->fov = ft_atodbl(array[3]), 0, 180)))
			error_exit("ERREUR FOV", d);
	cam->pos = parse_vector(array[1], d);
	cam->dir = parse_vector(array[2], d);
	if (!(ft_in_range(cam->dir.x, -1, 1)))
		error_exit("ERREUR DE LA DIRECTION CAMERA", d);
	if (!(ft_in_range(cam->dir.y, -1, 1)))
		error_exit("ERREUR DE LA DIRECTION CAMERA", d);
	if (!(ft_in_range(cam->dir.z, -1, 1)))
		error_exit("ERREUR DE LA DIRECTION CAMERA", d);
	cam->dir = normale_tuple(cam->dir);
	cam->rot_mat = create_matrice(cam->dir);
}

extern int      parse_camera(t_data *g_win, const char *lines)
{
    char    **array;
	 t_cam	*cam;

    array = ft_split(lines, ' ');
	cam = create_cam(g_win);
    if (!check_camera(g_win, array))
        error_exit("ERREUR D'IMPLEMENTAION CAMERA", g_win);
	checked_value_cam(array, cam, g_win);
	if (!lst_new_back(&(g_win->list_cam), cam))
		error_exit("Impossible d'allouer la cam", g_win);
    return (0);
}
