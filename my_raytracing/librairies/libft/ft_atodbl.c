/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:11:57 by matraore          #+#    #+#             */
/*   Updated: 2020/12/24 16:59:46 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double				ft_exp_dbl(int base, unsigned int power)
{
	double			product;
	unsigned int	i;

	if (base == 0 && power == 0)
		return (1.0);
	if (base == 0)
		return (0.0);
	if (power == 0)
		return (1.0);
	product = 1.0;
	i = 0;
	while (i < power)
	{
		product *= (double)base;
		i++;
	}
	return (product);
}

static void		add_decimal(double *total, const char *str, int sign)
{
	int			i;

	if (*str != '.')
		return ;
	i = 1;
	while (ft_isdigit(*(++str)))
		*total += (double)(*str - '0') / ft_exp_dbl(10, i++) * sign;
}

double			ft_atodbl(const char *str)
{
	double		total;
	int			subtotal;
	int			sign;

	subtotal = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str == '+')
		sign = 1;
	else
		str--;
	str++;
	while (ft_isdigit(*str))
	{
		subtotal = subtotal * 10 + (double)(*str - '0');
		str++;
	}
	total = (double)subtotal * sign;
	add_decimal(&total, str, sign);
	return (total);
}