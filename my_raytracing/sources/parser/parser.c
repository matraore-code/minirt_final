/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:09:00 by matraore          #+#    #+#             */
/*   Updated: 2020/12/29 10:54:34 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

static int g_res;
static int g_am;
// static int	parse_camera(const char *lines)
// {
// 	char **array;

// 	array = ft_split(lines, ' ');
// 	printf("c : {%s} ", array[1]);
// 	printf("{%s}\n", array[3]);
// 	return (0);
// }

void	checke_elemt(t_data *g_win, char *c)
{
	char	*str;

	str = ft_strdup("RAcltsp");
	while (*c != '\0')
    {
        	if (*c == '#' || *c == '\n')
				break ;
			if (ft_ischarset(str, *c))
			{
				if (*c == 82)
					g_res++;
				if (*c == 65)
					g_am++;
				if (g_res > 1 || g_am > 1)
					error_exit("RESOLUTIN OU AMBIANT DEFINIES 2 FOIS",g_win);
				else
					parse_element(g_win, c);	
			}
			c++;
    }
	
}

void		is_defined(t_data *g_win)
{
	if (!(g_win->res.is_def))
		error_exit("RESOLUTION NON DEFINIE", g_win);
	if (!(g_win->ambi.is_def))
		error_exit("LUMIERE AMBIANTE NON DEFINIE", g_win);
	if (!(g_win->list_cam.content))
		error_exit("CAMERA NON DEFINIE", g_win);
}

static int	parse_element(t_data *g_win,const char *lines)
{
	if (!(ft_strncmp(lines, "R", 1)))
		parse_resolution(g_win, lines);
	if (!(ft_strncmp(lines, "A", 1)))
		parse_ambiant(g_win, lines);
	if (!(ft_strncmp(lines, "c", 1)))
	{
		if (!(ft_strncmp(lines, "cy", 2)))
			printf("okay");
		else 
			parse_camera(g_win, lines);
	}
	if (!(ft_strncmp(lines, "s", 1)))
	{
		if (!(ft_strncmp(lines, "sq", 2)))
			printf("okay !!!");
		else if (!(ft_strncmp(lines, "sp", 2)))
			parse_sphere(g_win, lines);
	}
	if (!(ft_strncmp(lines,"l", 1)))
		parse_light(g_win, lines);
	// if (!(ft_strncmp(lines, "t", 1)))
	// 	parse_triangle(g_win, lines);
	// if (!(ft_strncmp(lines, "p", 1)))
	// 	parse_plan(g_win, lines);
	return (0);
}

void        get_scene_info(t_data *g_win, const char *filename)
{
    char        *lines;
    int         fd;
	int			i;

	i = 0;
	g_res = 0;
	g_am = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		error_exit("echec d'ouverture du fichier", g_win);
	while (1)
	{
		i = get_next_line(fd, &lines); 
	 	checke_elemt(g_win, lines);
	 	if (i == 0)
	 		break;
	}
    is_defined(g_win);
	g_win->camera = g_win->list_cam.content;
}
