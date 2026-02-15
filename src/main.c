/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:11:15 by jessica           #+#    #+#             */
/*   Updated: 2026/02/15 07:27:29 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	tester(t_scene *scene);
void		print_scene(t_scene *scene);

int	main(int argc, char **argv)
{
	t_scene		*scene;

	if (argc < 2)
		return (0);
	scene = read_image(argv[1]);
	if (!scene)
		return (1);
	tester(scene);
	free_scene(&scene);
	return (0);
}

static void	tester(t_scene *scene)
{
	print_scene(scene);
	test_matrix_comparison();
	test_matrix_multiplication();
	test_transposition();
	test_mult_matrix_id();
	test_determinant();
	test_submatrix();
	test_minor();
	test_final_determinant();
	test_is_invertible();
	test_inverse_matrix_basic();
	test_muilt_inverse_product();
}

void	print_error(char *error, bool clean)
{
	ft_putendl_fd("Error", 2);
	if (!error)
		return ;
	ft_putendl_fd(error, 2);
	if (clean)
		free(error);
}

void	free_scene(t_scene **scene)
{
	lst_clear_object(&(*scene)->objects);
	if ((*scene)->light)
		free((*scene)->light->light_point);
	free((*scene)->light);
	if ((*scene)->camera)
	{
		free((*scene)->camera->view_point);
		free((*scene)->camera->orientation_vector);
	}
	free((*scene)->camera);
	if ((*scene)->amb_light)
		free((*scene)->amb_light->colors);
	free((*scene)->amb_light);
	free(*scene);
	*scene = NULL;
}
