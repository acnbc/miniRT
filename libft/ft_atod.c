/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:34 by jesda-si          #+#    #+#             */
/*   Updated: 2026/01/01 16:28:51 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	fraction(const char *nptr);

double	ft_atod(const char *nptr)
{
	int		i;
	double	nb;
	double	frac;
	int		neg;

	frac = 0;
	neg = 1;
	nb = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	frac = fraction(&nptr[i]);
	return ((nb + frac) * neg);
}

static double	fraction(const char *nptr)
{
	double	nb;
	int		i;

	i = 0;
	if (nptr[i] == '.')
		i++;
	nb = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb / (i * 10));
}
