/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:52:53 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 02:16:35 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_tuple	point(double x, double y, double z);
static t_tuple	color(double r, double g, double b);
static bool		tuple_is_equal(t_tuple *a, t_tuple *b);
static void	create_point_light(t_light *p_light, t_tuple point, t_tuple color);

void	test_lighting(void)
{
	t_material		material;
	t_matrix		position;
	t_matrix		eyev;
	t_matrix		normalv;
	t_light			light;
	t_tuple			result;
	t_tuple			expected;
	t_light_base 	base;

	printf("\n================ LIGHTING DEBUG ================\n");

	default_material(&material);
	init_point(&position, 0, 0, 0);

	// Cenário 1: Olho (câmara) entre a luz e a superfície
	init_vector(&eyev, 0, 0, -1);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(&light, point(0, 0, -10), color(1, 1, 1));
	base = calc_light_base(&light, &position, &material, &normalv);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(1.9, 1.9, 1.9);
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 1\n");
	else
		printf("KO: Cenário 1\n");

	// Cenário 2: Olho entre a luz e superfície, mas olho com offset de 45 graus
	init_vector(&eyev, 0, sqrt(2)/2, -sqrt(2)/2);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(&light, point(0, 0, -10), color(1, 1, 1));
	base = calc_light_base(&light, &position, &material, &normalv);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(1.0, 1.0, 1.0); // Apenas ambiente e difusa
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 2\n");
	else
		printf("KO: Cenário 2\n");

	// Cenário 3: Olho oposto à superfície, luz com offset de 45 graus
	init_vector(&eyev, 0, 0, -1);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(&light, point(0, 10, -10), color(1, 1, 1));
	base = calc_light_base(&light, &position, &material, &normalv);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(0.7364, 0.7364, 0.7364); 
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 3\n");
	else
		printf("KO: Cenário 3\n");

	// Cenário 4: Olho diretamente no caminho do vetor de reflexão
	init_vector(&eyev, 0, -sqrt(2)/2, -sqrt(2)/2);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(&light, point(0, 10, -10), color(1, 1, 1));
	base = calc_light_base(&light, &position, &material, &normalv);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(1.6364, 1.6364, 1.6364); 
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 4\n");
	else
		printf("KO: Cenário 4\n");

	// Cenário 5: Luz posicionada atrás da superfície
	init_vector(&eyev, 0, 0, -1);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(&light, point(0, 0, 10), color(1, 1, 1));
	base = calc_light_base(&light, &position, &material, &normalv);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(0.1, 0.1, 0.1); // Apenas iluminação ambiente
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 5\n");
	else
		printf("KO: Cenário 5\n");
}

static t_tuple	point(double x, double y, double z)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.is_point = 1;
	return (tuple);
}

static t_tuple	color(double r, double g, double b)
{
	return (point(r, g, b));
}

static bool	tuple_is_equal(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return (false);
	return (is_equal(a->x, b->x)
		&& is_equal(a->y, b->y)
		&& is_equal(a->z, b->z));
}

static void	create_point_light(t_light *p_light, t_tuple point, t_tuple color)
{
	init_point(&p_light->point, point.x, point.y, point.z);
	p_light->intensity = color;
}