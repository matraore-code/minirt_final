#include "../../../includes/outils.h"

void free_list(t_list *list, void (*func)(void *))
{
    t_list  *tmp;

    while (list)
    {
        tmp = list->next;
        func(list->content);
		free(list);
		list = tmp;
    }

}

void free_all(t_data *data)
{
    if (data->objects)
        free_list(data->objects, &free);
}

void error_exit(char *err, t_data *data)
{
    ft_putstr_fd("Erreur : ");
    ft_putstr_fd(err);
    ft_putstr_fd("\n");
    if (data)
        free_all(data);
    exit(1);
}

void exit_free(t_data *data)
{
    free_all(data);
    exit(1);
}