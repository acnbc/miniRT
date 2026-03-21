/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:01:59 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 16:05:40 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static const char	*get_id_name(t_id id);
static void			print_object_details(t_object *obj);
static void			print_matrix_as_tuple(char *label, const t_matrix *t);
static void			print_rgb(char *label, t_rgb c);


void	print_scene(t_scene *scene)
{
	t_object	*curr;
	int			i;

	if (!scene)
	{
		printf("Scene is NULL\n");
		return ;
	}
	printf("================ SCENE DEBUG ================\n");
	if (scene->amb_light)
	{
		printf("[%s]\n", get_id_name(scene->amb_light->id));
		printf("	Ratio: %.2f\n", scene->amb_light->light_ratio);
		print_rgb("Color", scene->amb_light->colors);
	}
	if (scene->camera)
	{
		printf("\n[%s]\n", get_id_name(scene->camera->id));
		print_matrix_as_tuple("View Point", &scene->camera->view_point);
		print_matrix_as_tuple("Orientation", &scene->camera->orientation_vector);
		printf("	FOV: %.2f\n", scene->camera->field_of_view);
	}
	if (scene->light)
	{
		printf("\n[%s]\n", get_id_name(scene->light->id));
		print_matrix_as_tuple("Position", &scene->light->light_point);
		printf("	Brightness: %.2f\n", scene->light->brightness);
		print_rgb("Color", scene->light->colors);
	}
	printf("\n[OBJECTS LIST]\n");
	curr = scene->objects;
	i = 0;
	while (curr)
	{
		printf("  %d. ID: %s\n", i++, get_id_name(curr->id));
		print_matrix_as_tuple("Coords", &curr->coord);
		print_rgb("Color", curr->colors);
		print_object_details(curr);
		printf("	----------\n");
		curr = curr->next;
	}
	printf("=============================================\n");
}

static void	print_object_details(t_object *obj)
{
	if (!obj)
		return ;

	if (obj->id == sp && obj->object.sphere)
	{
		printf("	Diameter: %.2f\n", obj->object.sphere->diameter);
	}
	else if (obj->id == pl && obj->object.plane)
	{
		print_matrix_as_tuple("Normal", &obj->object.plane->normalized_vector);
	}
	else if (obj->id == cy && obj->object.cylinder)
	{
		print_matrix_as_tuple("Normal", &obj->object.cylinder->normalized_vector);
		printf("	Diameter: %.2f | Height: %.2f\n", 
			obj->object.cylinder->diameter, obj->object.cylinder->height);
	}
}

static const char	*get_id_name(t_id id)
{
	if (id == A)
		return ("Ambient Light (A)");
	if (id == C)
		return ("Camera (C)");
	if (id == L)
		return ("Light (L)");
	if (id == sp)
		return ("Sphere (sp)");
	if (id == pl)
		return ("Plane (pl)");
	if (id == cy)
		return ("Cylinder (cy)");
	return "Unknown";
}

static void	print_matrix_as_tuple(char *label, const t_matrix *t)
{
	char	*str;

	str = "Vector";
	if (is_equal(t->m_4x1[3], 1.0))
		str = "Point";
	printf("	%s: [%.2f, %.2f, %.2f] (%s)\n",
		label, t->m_4x1[0], t->m_4x1[1], t->m_4x1[2], str);
}

static void	print_rgb(char *label, t_rgb c)
{
	printf("	%s: R:%d G:%d B:%d\n", label, c.r, c.g, c.b);
}
