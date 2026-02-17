/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:42:29 by jessica           #+#    #+#             */
/*   Updated: 2026/02/16 21:10:07 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	draw_test_square(t_scene *scene)
{
	int			x;
	int			y;
	int			color;
	const t_rgb	red = {0, 255, 0};

	color = conver_color(scene->window->mlx_ptr, (t_rgb *)&red, 255);

	// Define o tamanho do quadrado (ex: 100x100)
	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			// Verifica se o pixel está dentro dos limites da janela
			if (x < scene->window->size_x && y < scene->window->size_y)
			{
				pixel_put(scene->window->img, x, y, color);
			}
			x++;
		}
		y++;
	}
	// Após desenhar na memória, envia a imagem para a janela[cite: 49].
	mlx_put_image_to_window(scene->window->mlx_ptr, scene->window->win_ptr,
	scene->window->img->ptr, 0, 0);
}
