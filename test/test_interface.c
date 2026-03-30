/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:42:29 by jessica           #+#    #+#             */
/*   Updated: 2026/03/30 03:01:46 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void		init_sphere(t_object *sphere);
static t_ray	init_ray(t_matrix *ray_origin, double world_x, double world_y,
					double wall_z);
static double	simplified_hit(t_intersect inter[2]);
static t_tuple	lighting_calc(t_light *light, t_ray *ray, t_object *sphere,
					double hit_t);

void	draw_test_3d_sphere(t_scene *scene)
{
	int				canvas_pixels;
	double			wall_z;
	double			wall_size;
	double			pixel_size;
	double			half;
	t_matrix		ray_origin;
	t_object		sphere;
	int 			y;
	int 			x;
	double			world_y;
	double			world_x;
	t_ray 			ray;
	t_intersect		inter[2];
	double 			hit_t;
	t_tuple			pixel_color;
	unsigned int	final_mlx_color;


	// 1. Configurações da Câmera e da "Parede" (Canvas)
	canvas_pixels = 400; // Tamanho da janela (400x400)
	wall_z = 10.0; // A parede onde o raio vai bater fica na coordenada Z = 10
	wall_size = 7.0;  // O tamanho físico da parede
	pixel_size = wall_size / canvas_pixels; // O tamanho de um pixel no mundo
	half = wall_size / 2.0;

	// 2. Inicialização do Mundo
	init_point(&ray_origin, 0, 0, -5); // A câmera está no Z = -5, olhando para frente

	// 3. Inicialização da Esfera e Material
	init_sphere(&sphere);

	// 4. Inicialização da Luz
	scene->light->intensity = (t_tuple){1.0, 1.0, 1.0, 0}; // Luz branca forte

	// init_point(&scene->light->point, 10, -10, -10); // teste padrão
	init_point(&scene->light->point, 0, 0, -20); // ponto de luz no centro

	printf("desenhando cena...\n");

	// 5. O Loop de Renderização (Ray Casting)
	y = -1;
	while (++y < canvas_pixels)
	{
		// Calcula a coordenada Y real na parede (o Y do MLX cresce para baixo, o Y do mundo cresce para cima)
		world_y = half - y * pixel_size;

		x = -1;
		while (++x < canvas_pixels)
		{
			// Calcula a coordenada X real na parede
			world_x = -half + x * pixel_size;

			// 6. Criar o Raio
			ray = init_ray(&ray_origin, world_x, world_y, wall_z);

			// 7. Testar Interseção
			sp_intersect(inter, &sphere, &ray);

			// Interseção não ocorreu
			if (inter[0].t <= 0 && inter[1].t <= 0)
				continue ;

			hit_t = simplified_hit(inter);

			// 8. O Raio acertou! Vamos calcular a Iluminação
			pixel_color = lighting_calc(scene->light, &ray, &sphere, hit_t);

			// 10. Pintar na imagem
			final_mlx_color = convert_color(&pixel_color);
			pixel_put(scene->window, x, y, final_mlx_color);
		}
	}

	printf("cena desenhada!\n");
	mlx_put_image_to_window(scene->window->mlx_ptr, scene->window->win_ptr,
		scene->window->img->ptr, 0, 0);
}

static void	init_sphere(t_object *sphere)
{
	t_sphere	object_sphere;

	if (!sphere)
		return ;
	sphere->id = sp;
	init_identity_matrix(&sphere->coord, 4); // Esfera no centro, sem transformações
	object_sphere.diameter = 2;
	sphere->object.sphere = &object_sphere;
	sphere->object.plane = NULL;
	sphere->object.cylinder = NULL;
	default_material(&sphere->material);

	sphere->material.color = (t_tuple){7, 0.7, 0, 0}; // sol
	// sphere->material.color = (t_tuple){1.0, 0.2, 1.0, 0}; // teste padrão (Roxo fosco com brilho)
}

static t_ray	init_ray(t_matrix *ray_origin, double world_x, double world_y,
					double wall_z)
{
	t_matrix	target;
	t_matrix	unnormalized_dir;
	t_matrix	direction;
	t_ray		ray;

	init_point(&target, world_x, world_y, wall_z);
	subtract_tuple(&unnormalized_dir, &target, ray_origin);
	vector_normalization(&direction, &unnormalized_dir);

	create_ray(&ray, *ray_origin, direction);
	return (ray);
}

// Lógica simplificada de "Hit" (Pega o menor t positivo)
static double	simplified_hit(t_intersect inter[2])
{
	double	hit_t;

	if (inter[0].t > 0 && inter[1].t > 0)
		hit_t = fmin(inter[0].t, inter[1].t);
	else if (inter[0].t > 0)
		hit_t = inter[0].t;
	else
		hit_t = inter[1].t;
	return (hit_t);
}

static t_tuple	lighting_calc(t_light *light, t_ray *ray, t_object *sphere,
					double hit_t)
{
	t_tuple			pixel_color;
	t_matrix		hit_point;
	t_matrix		normal_v;
	t_matrix		eye_v;
	t_light_base	base;

	position(&hit_point, ray, hit_t);
	normal_at(&normal_v, sphere, &hit_point);
	negate_tuple(&eye_v, &ray->direc); // O vetor olho aponta na direção contrária do raio

	// 9. A Mágica Final
	base = calc_light_base(light, &hit_point, &sphere->material, &normal_v);
	pixel_color = lighting(&base, &sphere->material, &eye_v, &normal_v);
	return (pixel_color);
}
