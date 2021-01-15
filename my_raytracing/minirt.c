#include "includes/minirt.h"

void handle_argument_error(int argc, char **argv, t_data *d)
{
    int     length;
    char    *file;

    if (argc != 2 || argc != 3)
        error_exit("Le nombre d'argument invalide", d);
    if (argc == 3)
    {
        if (!(ft_strncmp(argv[2], "--save", 5)))
                printf("ok");
        else
            error_exit("Argument invalide", d);    
    }
    length = ft_strlen(argv[1]);
    file = argv[1];
    argv += length - 3;
    if (ft_strncmp(file, ".rt", 3))
        error_exit("Fichier non supporte", d);
}

int main(int argc, char **argv)
{
    t_data  *g_win;
    char    *filename;

    handle_argument_erro(argc, argv, g_win);
    filename = ft_strdup(argv[1]);
    get_scene_info(g_win, filename);
    if (!(initialise_win(g_win)))
        error_exit("Echec d'ouverture de la fenetre", g_win);
    mlx_loop(g_win->mlx_info.mlx);
    return (0);
}