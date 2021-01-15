#include "../includes/minirt.h"
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124

void	exit_win(int keycode, t_data *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx_info.mlx, data->mlx_info.mlx_win);
	exit_free(data);
}


void	camera_prec(int keycode, t_data *data)
{
	t_list		*cameras;

	(void)keycode;
	cameras = data->list_cam;
	while (cameras->next)
	{
		if (cameras->content == data->camera)
			break ;
		cameras = cameras->next;
	}
	if (cameras->prev)
		data->camera = cameras->prev->content;
	else if (!cameras->prev)
	{
		while (cameras->next)
			cameras = cameras->next;
		data->camera = cameras->content;
	}
}

void	camera_suiv(int keycode, t_data *data)
{
	t_list		*cameras;

	(void)keycode;
	cameras = data->list_cam;
	while (cameras->next)
	{
		if (cameras->content == data->camera)
			break ;
		cameras = cameras->next;
	}
	if (cameras->next)
		data->camera = cameras->next->content;
	else if (!cameras->next)
	{
		while (cameras->prev)
			cameras = cameras->prev;
		data->camera = cameras->content;
	}
}

int				key_hook(int keycode, void *param)
{
	t_data	*g_win;

	g_win = (t_data *)param;
	if (keycode == KEY_ESC)
		exit_win(keycode, g_win);
	if (keycode == KEY_LEFT)
		camera_prec(keycode, g_win);
	if (keycode == KEY_LEFT)
		camera_suiv(keycode, g_win);
	return (0);
}