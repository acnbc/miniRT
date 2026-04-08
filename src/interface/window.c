/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:06:18 by jessica           #+#    #+#             */
/*   Updated: 2026/03/21 16:11:01 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static char	*create_title(char *file);

void	create_window(t_scene *scene, char *file)
{
	scene->window = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!scene->window)
		exit_error(ERR_MALLOC, NULL);
	scene->window->title = create_title(file);
	if (!scene->window->title)
		exit_error(ERR_MALLOC, NULL);
	scene->window->mlx_ptr = mlx_init();
	if (!scene->window->mlx_ptr)
		exit_error(ERR_MLX_INIT, NULL);
	scene->window->size_x = 1200;
	scene->window->size_y = 1000;
	scene->window->win_ptr = mlx_new_window(scene->window->mlx_ptr,
			scene->window->size_x, scene->window->size_y, scene->window->title);
	if (!scene->window->win_ptr)
		exit_error(ERR_MLX_NEW_WIN, NULL);
}

void	create_image(t_window *win)
{
	win->img = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!win->img)
		exit_error(ERR_MALLOC, NULL);
	win->img->ptr = mlx_new_image(win->mlx_ptr, win->size_x, win->size_y);
	if (!win->img->ptr)
	{
		free(win->img);
		exit_error(ERR_MLX_NEW_IMG, NULL);
	}
	win->img->addr = mlx_get_data_addr(win->img->ptr, &win->img->bits_per_pixel,
			&win->img->size_line, &win->img->endian);
	if (!win->img->addr)
	{
		free_image(&win->img, win->mlx_ptr);
		exit_error(ERR_MLX_GET_DATA_ADDR, NULL);
	}
}

void	free_window(t_window **win)
{
	if (!win || !*win)
		return ;
	if ((*win)->title)
		free((*win)->title);
	if ((*win)->img)
		free_image(&(*win)->img, (*win)->mlx_ptr);
	if ((*win)->win_ptr)
	{
		mlx_clear_window((*win)->mlx_ptr, (*win)->win_ptr);
		mlx_destroy_window((*win)->mlx_ptr, (*win)->win_ptr);
	}
	if ((*win)->mlx_ptr)
	{
		mlx_destroy_display((*win)->mlx_ptr);
		free((*win)->mlx_ptr);
	}
	free(*win);
	*win = NULL;
}

void	free_image(t_image **img, void *mlx_ptr)
{
	if (!img || !*img)
		return ;
	if ((*img)->ptr)
		mlx_destroy_image(mlx_ptr, (*img)->ptr);
	free((*img));
	*img = NULL;
}

static char	*create_title(char *file)
{
	char	**strs;
	char	*title;
	size_t	len;
	int		index;

	strs = ft_split(file, '/');
	if (!strs)
		exit_error(ERR_MALLOC, NULL);
	index = ft_split_len(strs) - 1;
	len = ft_strlen(strs[index]);
	title = ft_substr(strs[index], 0, len - 3);
	ft_split_free(&strs);
	return (title);
}
