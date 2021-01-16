/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:53:59 by matraore          #+#    #+#             */
/*   Updated: 2021/01/16 09:44:02 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*temp;

	if (alst == NULL || *alst == NULL)
		return ;
	node = *alst;
	*alst = NULL;
	while (node != NULL)
	{
		// if (node->content != NULL && del != NULL)
		// 	del(node->content, node->content_size);
		temp = node;
		node = node->next;
		free(temp);
	}
}