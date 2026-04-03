/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:32:33 by jessica           #+#    #+#             */
/*   Updated: 2026/04/03 01:04:36 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

typedef struct s_tuple
{
	union
	{
		struct
		{
			double	x;
			double	y;
			double	z;
			bool	is_point;
		};
		struct
		{
			double	r;
			double	g;
			double	b;
		};
	};
}	t_tuple;

typedef t_tuple	t_rgb;

typedef struct s_matrix
{
	union
	{
		double		m_2x2[4];
		double		m_4x1[4];
		double		m_3x3[9];
		double		m_4x4[16];
	};
	int				rows;
	int				cols;
}	t_matrix;

typedef struct s_material
{
	t_rgb	color;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_ndc
{
	double	x;
	double	y;
}	t_ndc;

typedef enum e_msg_error
{
	ERR_MALLOC = 1,
	ERR_ARGS,
	ERR_FILE_FORMAT,
	ERR_FILE_READ,
	ERR_DUPLICATE,
	ERR_RANGE,
	ERR_MISSING_ELEM,
	ERR_MISSING_ARGS,
	ERR_ID,
	ERR_MLX_INIT,
	ERR_MLX_NEW_WIN,
	ERR_MLX_NEW_IMG,
	ERR_MLX_GET_DATA_ADDR
}	t_msg_error;

typedef struct s_light_calc
{
	t_rgb		effective_color;
	t_matrix	light_v;
	double		light_dot_normal;
	t_rgb		intensity;
	t_rgb		ambient;
}	t_light_base;

#endif