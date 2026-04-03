/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:00:00 by anogueir         #+#    #+#             */
/*   Updated: 2026/03/31 00:00:00 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

# define CAM_UP_DOT_EPS 1e-6

void	compute_camera_axes(t_cam_basis *basis, const t_camera *camera)
{
	t_matrix	world_up;
	t_matrix	tmp;

	vector_normalization(&basis->forward, &camera->orientation_vector);
	init_vector(&world_up, 0, 1, 0);
	if (fabs(dot_product(&basis->forward, &world_up)) > 1.0 - 1e-6)
		init_vector(&world_up, 0, 0, 1);
	cross_product(&tmp, &basis->forward, &world_up);
	vector_normalization(&basis->right, &tmp);
	cross_product(&tmp, &basis->right, &basis->forward);
	vector_normalization(&basis->up, &tmp);
}

void	init_viewport(t_viewport *viewport, t_scene *scene)
{
	viewport->fov_rad = scene->camera->field_of_view * (acos(-1.0) / 180.0);
	viewport->half_height = tan(viewport->fov_rad / 2.0);
	viewport->aspect = scene->window->size_x / (double)scene->window->size_y;
	viewport->half_width = viewport->half_height * viewport->aspect;
}

void	map_pixel_ndc(t_scene *scene, int x, int y, t_ndc *out)
{
	out->x = ((x + 0.5) / (double)scene->window->size_x) * 2.0 - 1.0;
	out->y = 1.0 - ((y + 0.5) / (double)scene->window->size_y) * 2.0;
}

void	ray_gen_init(t_ray_gen *context, t_scene *scene)
{
	context->camera = scene->camera;
	compute_camera_axes(&context->basis, scene->camera);
	init_viewport(&context->viewport, scene);
}

void	make_primary_ray(t_ray_gen *context, const t_ndc *ndc, t_ray *ray)
{
	t_matrix	scaled_r;
	t_matrix	scaled_u;
	t_matrix	offset;
	t_matrix	dir;

	scalar_multiplication(&scaled_r, &context->basis.right,
		ndc->x * context->viewport.half_width);
	scalar_multiplication(&scaled_u, &context->basis.up,
		ndc->y * context->viewport.half_height);
	add_tuples(&offset, &scaled_r, &scaled_u);
	add_tuples(&dir, &context->basis.forward, &offset);
	vector_normalization(&ray->direc, &dir);
	ray->ori = context->camera->view_point;
}
