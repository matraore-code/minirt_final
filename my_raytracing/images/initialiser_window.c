#include "../includes/minirt.h"

int initialise_img(t_data *g_win)
{
    g_win->mlx_info.mlx_data.img = mlx_new_image(g_win->mlx_info.mlx,
                g_win->res.size_x, g_win->res.size_y);
    g_win->mlx_info.mlx_data.addr = mlx_get_data_addr(
        g_win->mlx_info.mlx_data.img, &g_win->mlx_info.mlx_data.bits_per_pixel,
        &g_win->mlx_info.mlx_data.line_length,
        &g_win->mlx_info.mlx_data.endian);
    return (1);
}

int render(t_data *g_win)
{
    t_color   *shape;
    int x;
    int y;

    shape = get_shape(g_win);
    x = 0;
    while (x < g_win->res.size_x)
    {
        y = 0;
        while (y < g_win->res.size_y)
        {
            pixel_put(g_win->mlx_info.mlx_data,
            x, y, shape[x * g_win->res.size_x + y]);
            y++;
        }
        x++;
    }
    free(shape);
    mlx_put_image_to_window(g_win->mlx_info.mlx, g_win->mlx_info.mlx_win,
        g_win->mlx_info.mlx_data.img, 0 , 0);
    return (0);
}

static int  quitte(t_data *g_win)
{
    exit_free(g_win);
    return (1);
}

int initialise_win(t_data *g_win)
{
    if (!(g_win->mlx_info.mlx = mlx_init()))
        return (0);
    g_win->mlx_info.mlx_win = mlx_new_window(g_win->mlx_info.mlx,
                g_win->res.size_x, g_win->res.size_y, "MINIRT");
    if (!g_win->mlx_info.mlx_win)
        return (0);
    if (!(initialise_img(g_win)))
        return (0);
    mlx_hook(g_win->mlx_info.mlx_win, 17, 0L, &quitte, g_win);
    mlx_key_hook(g_win->mlx_info.mlx_win, &key_hook, g_win);
	mlx_loop_hook(g_win->mlx_info.mlx, &render, g_win);
    return(1);
}