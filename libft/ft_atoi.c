/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:58:07 by jesda-si          #+#    #+#             */
/*   Updated: 2026/01/03 16:25:29 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	neg;

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
	return (nb * neg);
}
