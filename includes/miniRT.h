/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anogueir <anogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:50:52 by jessica           #+#    #+#             */
/*   Updated: 2026/01/05 12:40:21 by anogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "types.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "math.h"


// adicionar aqui as funcoes que forem criadas
void	*safe_malloc(size_t size);

/*------------- APAGAR ------------------*/
# include "tests.h"

#endif