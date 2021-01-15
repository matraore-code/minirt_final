/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:28:08 by matraore          #+#    #+#             */
/*   Updated: 2020/12/22 17:30:39 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_ischarset(const char *charset, int c)
{
    int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
		return (1);
        i++;
	}
    return (0);
}