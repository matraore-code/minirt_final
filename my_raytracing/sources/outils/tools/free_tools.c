/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:55:34 by matraore          #+#    #+#             */
/*   Updated: 2020/12/22 16:56:11 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tools.h"

t_list	*lst_new(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_list	*lst_new_back(t_list **node, void *content)
{
	t_list	*new;
	t_list	*node_cpy;

	if (!node)
		return (NULL);
	if (!*node)
	{
		*node = lst_new(content);
		return (*node);
	}
	node_cpy = *node;
	while (node_cpy->next)
		node_cpy = node_cpy->next;
	new = lst_new(content);
	new->prev = node_cpy;
	node_cpy->next = new;
	return (new);
}

void	lst_new_front(t_list **node, void *content)
{
	t_list	*new;

	if (!node)
		return ;
	if (!*node)
	{
		*node = lst_new(content);
		return ;
	}
	new = lst_new(content);
	new->next = *node;
	(*node)->prev = new;
	*node = new;
}

void	lst_remove(t_list *node, void (*free_func)(void *))
{
	if (!node)
		return ;
	free_func(node->content);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}