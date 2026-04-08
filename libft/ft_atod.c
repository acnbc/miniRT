/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:34 by jesda-si          #+#    #+#             */
/*   Updated: 2026/04/08 17:16:43 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	fraction(const char *nptr);

double	ft_atod(const char *nptr)
{
	int		i;
	double	nb;
	double	neg;

	neg = 1;
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

static double	fraction(const char *nptr)
{
	double	nb;
	int		i;
	int		f;

	i = 0;
	if (nptr && nptr[i] == '.')
		i++;
	nb = 0;
	f = 1;
	while (nptr && nptr[i] && ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
		f *= 10;
	}
	return (nb / f);
}
