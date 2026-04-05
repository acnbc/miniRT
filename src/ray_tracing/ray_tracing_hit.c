/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:00:00 by anogueir         #+#    #+#             */
/*   Updated: 2026/03/31 00:00:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

size_t	count_objects(t_object *objects)
{
	size_t	n;

	n = 0;
	while (objects)
	{
		n++;
		objects = objects->next;
	}
	return (n);
}

t_intersect	*hit(t_intersect *buf, size_t n)
{
	int	min;
	int	i;

	i = 0;
	min = -1;
	while ((size_t)i < n)
	{
		if (buf[i].t >= 0)
		{
			if ((min == -1 || buf[i].t < buf[min].t) && buf[i].obj != NULL)
				min = i;
		}
		i++;
	}
	if (min == -1)
		return (NULL);
	return (&buf[min]);
}

bool	resolve_closest_hit(t_intersect *buf, size_t n, t_intersect *out_hit)
{
	t_intersect		*winner;

	if (n == 0)
	{
		free(buf);
		return (false);
	}
	winner = hit(buf, n);
	if (winner)
		*out_hit = *winner;
	free(buf);
	return (winner != NULL);
}

bool	closest_hit(t_object *objects, t_ray *ray,
		t_intersect *out_hit)
{
	t_intersect	pair[2];
	t_intersect	*buf;
	size_t		cap;
	size_t		n;

	n = 0;
	cap = count_objects(objects);
	if (cap == 0)
		return (false);
	buf = (t_intersect *)safe_malloc(4 * cap * sizeof(t_intersect));
	n += fill_hits(objects, ray, buf, pair);
	return (resolve_closest_hit(buf, n, out_hit));
}
