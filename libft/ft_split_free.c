/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:45:28 by jesda-si          #+#    #+#             */
/*   Updated: 2026/01/01 17:15:19 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char ***split)
{
	int	i;

	if (!split || !*split)
		return ;
	i = -1;
	while ((*split)[++i])
		free((*split)[i]);
	free(*split);
	*split = NULL;
}
