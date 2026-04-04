/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:52:53 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 02:28:36 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_tuple	point(double x, double y, double z);
static t_rgb	color(double r, double g, double b);
static bool		tuple_is_equal(t_rgb *a, t_rgb *b);
static void	create_point_light(t_light *p_light, t_tuple point, t_rgb color);

void	test_lighting(void)
{
	t_material		material;
	t_matrix		position;
	t_matrix		eyev;
	t_matrix		normalv;
	t_scene			scene;
	t_tuple			result;
	t_tuple			expected;
	t_light_base 	base;
	t_amb_light		amb;
	t_light			light;
	t_hit_shade		in;

	printf("\n================ LIGHTING DEBUG ================\n");

	default_material(&material);
	init_point(&position, 0, 0, 0);
	amb.colors = (t_rgb){.r = 1, .g = 1, .b = 1};
	amb.light_ratio = 0.1;
	scene.amb_light = &amb;
	scene.light = &light;

	in.sc = &scene;
	in.mt = &material;
	in.nm = &normalv;
	in.pt = &position;

	// Cenário 1: Olho (câmara) entre a luz e a superfície
	init_vector(&eyev, 0, 0, -1);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(scene.light, point(0, 0, -10), color(1, 1, 1));
	base = calc_light_base(&in);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(1.9, 1.9, 1.9);
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 1\n");
	else
		printf("KO: Cenário 1\n");

	// Cenário 2: Olho entre a luz e superfície, mas olho com offset de 45 graus
	init_vector(&eyev, 0, sqrt(2)/2, -sqrt(2)/2);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(scene.light, point(0, 0, -10), color(1, 1, 1));
	base = calc_light_base(&in);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(1.0, 1.0, 1.0); // Apenas ambiente e difusa
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 2\n");
	else
		printf("KO: Cenário 2\n");

	// Cenário 3: Olho oposto à superfície, luz com offset de 45 graus
	init_vector(&eyev, 0, 0, -1);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(scene.light, point(0, 10, -10), color(1, 1, 1));
	base = calc_light_base(&in);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(0.7364, 0.7364, 0.7364); 
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 3\n");
	else
		printf("KO: Cenário 3\n");

	// Cenário 4: Olho diretamente no caminho do vetor de reflexão
	init_vector(&eyev, 0, -sqrt(2)/2, -sqrt(2)/2);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(scene.light, point(0, 10, -10), color(1, 1, 1));
	base = calc_light_base(&in);
	result = lighting(&base, &material, &eyev, &normalv);
	expected = color(1.6364, 1.6364, 1.6364); 
	if (tuple_is_equal(&result, &expected))
		printf("OK: Cenário 4\n");
	else
		printf("KO: Cenário 4\n");

	// Cenário 5: Luz posicionada atrás da superfície
	init_vector(&eyev, 0, 0, -1);
	init_vector(&normalv, 0, 0, -1);
	create_point_light(scene.light, point(0, 0, 10), color(1, 1, 1));
	base = calc_light_base(&in);
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

static t_rgb	color(double r, double g, double b)
{
	return ((t_rgb)point(r, g, b));
}

static bool	tuple_is_equal(t_rgb *a, t_rgb *b)
{
	if (!a || !b)
		return (false);
	return (is_equal(a->r, b->r)
		&& is_equal(a->g, b->g)
		&& is_equal(a->b, b->b));
}

static void	create_point_light(t_light *p_light, t_tuple point, t_rgb color)
{
	init_point(&p_light->point, point.x, point.y, point.z);
	p_light->intensity = color;
	p_light->colors = color;
	p_light->brightness = 1.0;
}