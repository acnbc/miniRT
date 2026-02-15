/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:52:10 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 07:56:15 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

t_object	*lst_new_object(char **infos, t_id id)
{
	t_object	*new;

	if (ft_split_len(infos) < 4)
		exit_error("invalid arguments", false, NULL);
	new = (t_object *)ft_calloc(1, sizeof(t_object));
	if (!new)
		exit_error("malloc error", false, NULL);
	new->id = id;
	new->coord = get_coord(infos[1], false);
	new->object = get_object_type(new->id, &infos[2]);
	new->colors = get_coolors(infos[ft_split_len(infos) - 1]);
	if (!new->object || !new->coord || !new->colors)
	{
		free(new->coord);
		free(new->object);
		free(new->colors);
		return (NULL);
	}
	return (new);
}

void	lst_add_back_object(t_object **lst, t_object *new)
{
	t_object	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new;
}

t_object	*lst_back_object(t_object *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_clear_object(t_object **lst)
{
	t_object	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->coord);
		free((*lst)->colors);
		if ((*lst)->id == pl)
		{
			free((*lst)->object->plane->normalized_vector);
			free((*lst)->object->plane);
		}
		if ((*lst)->id == cy)
		{
			free((*lst)->object->cylinder->normalized_vector);
			free((*lst)->object->cylinder);
		}
		if ((*lst)->id == sp)
			free((*lst)->object->sphere);
		free((*lst)->object);
		free((*lst));
		(*lst) = next;
	}
}
