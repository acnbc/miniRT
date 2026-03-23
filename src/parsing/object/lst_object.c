/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:52:10 by jessica           #+#    #+#             */
/*   Updated: 2026/03/17 23:25:27 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

t_object	*lst_new_object(char ***infos, t_id id)
{
	t_object	*new;
	t_msg_error	error;

	new = (t_object *)ft_calloc(1, sizeof(t_object));
	if (!new)
	{
		ft_split_free(infos);
		exit_error(ERR_MALLOC, NULL);
	}
	new->id = id;
	new->coord = get_coord(*infos, 1, false);
	get_object_type(new, infos, 2);
	error = get_coolors(&new->colors, *infos, ft_split_len(*infos) - 1);
	if (!error)
		error = valid_tuple(new->coord);
	if (error)
	{
		ft_split_free(infos);
		lst_clear_object(&new);
		exit_error(error, NULL);
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

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		if ((*lst)->id == pl)
			free((*lst)->object.plane);
		if ((*lst)->id == cy)
			free((*lst)->object.cylinder);
		if ((*lst)->id == sp)
			free((*lst)->object.sphere);
		free((*lst));
		(*lst) = next;
	}
	*lst = NULL;
}
