/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:14:34 by matraore          #+#    #+#             */
/*   Updated: 2021/01/17 14:28:02 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../librairies/libft/libft.h"
# include "../librairies/get_next_line/get_next_line.h"
# include "minirt.h"
# include  "math_tools.h"
# include "tools.h"
# include  "outils.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>


t_tuple				parse_vector(char *str, t_data *d);
extern int	parse_ambiant(t_data *g_win, const char *lines);
void        get_scene_info(t_data *g_win,const char *filename);
static int	parse_element(t_data *g_win, const char *lines);
int	parse_resolution(t_data *g_win, const char *lines);
t_color     parse_color(char **array, t_data *g_win);
int         fdigit(char *str);
int         fdigit_d(char *str);
int         ft_array_length(char **array);
extern int      parse_camera(t_data *g_win, const char *lines);
int         check_camera(t_data *g_win, char **str);
void			multi_camera(t_cam **cams, t_cam *new_cam);
t_cam		*create_cam();
t_light		*create_light();
int         check_light(t_data *g_win,char **str);
void			checked_value_light(char **array, t_light *light, t_data *g_win);
extern int      parse_light(t_data *g_win, const char *lines);
extern int      parse_sphere(t_data *g_win, const char *lines);
void			checked_value_sphere(t_data *g_win,char **arr, t_object *obj);
extern int      parse_plan(t_data *g_win, const char *lines);
void			checked_value_plan(t_data *g_win,char **arr, t_object *obj);
int         check_plan(t_data *g_win,char **str);


#endif
