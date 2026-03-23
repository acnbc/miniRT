/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:47:55 by jesda-si          #+#    #+#             */
/*   Updated: 2026/02/15 04:58:03 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(char const *s1, char const *set);
static int	end_index(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*str;

	start = start_index(s1, set);
	end = end_index(s1, set);
	size = end - start + 2;
	str = ft_substr(s1, start, size);
	return (str);
}

static int	start_index(char const *s1, char const *set)
{
	int	i;

	if (!s1 || !*s1)
		return (0);
	i = 0;
	while (i >= 0 && s1 && s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	end_index(char const *s1, char const *set)
{
	int	i;

	if (!s1 || !*s1)
		return (0);
	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && s1 && s1[i] && ft_strchr(set, s1[i]))
		i--;
	return (i - 1);
}
