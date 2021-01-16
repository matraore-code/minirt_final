/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 08:54:40 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:41:15 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/outils.h"
#include <stdio.h>

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
	if (data->list_cam)
		free_list(data->list_cam, &free);
	if (data->list_light)
		free_list(data->list_light, &free);
}

void error_exit(char *err, t_data *data)
{
    printf("Erreur:\n");
    printf("%s\n", err);
    if (data)
        free_all(data);
    exit(1);
}

void exit_free(t_data *data)
{
    free_all(data);
    exit(1);
}
