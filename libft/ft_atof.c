/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:34 by jesda-si          #+#    #+#             */
/*   Updated: 2026/03/11 23:05:59 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	fraction(const char *nptr);

float	ft_atof(const char *nptr)
{
	int		i;
	float	nb;
	float	neg;

	neg = 1.0;
	nb = 0;
	i = 0;
	while (nptr && ft_isspace(nptr[i]))
		i++;
	if (nptr && nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr && nptr[i] == '+')
		i++;
	while (nptr && nptr[i] && ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr && nptr[i])
		nb += fraction(&nptr[i]);
	return (nb * neg);
}

static float	fraction(const char *nptr)
{
	float	nb;
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (nptr && nptr[i] == '.')
		i++;
	nb = 0;
	while (nptr && nptr[i] && ft_isdigit(nptr && nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
		f *= 10;
	}
	return (nb / f);
}
