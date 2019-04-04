/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:40 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_mlx *e, int x, int y, t_color *clr)
{
	int		pos;

	if (e->design && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->image->img_bpp / 8) + (y * e->image->img_size_line);
		e->image->img_data[pos] = e->design % 256;
		e->image->img_data[pos + 1] = e->design >> 8 % 256;
		e->image->img_data[pos + 2] = e->design >> 16 % 256;
	}
	else if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * e->image->img_bpp / 8) + (y * e->image->img_size_line);
		e->image->img_data[pos] = clr->b;
		e->image->img_data[pos + 1] = clr->g;
		e->image->img_data[pos + 2] = clr->r;
	}
}

void	clear_image(t_mlx *e)
{
	mlx_destroy_image(e->mlx_ptr, e->image->img);
	e->image->img = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->image->img_data = mlx_get_data_addr(e->image->img, &(e->image->img_bpp),
		&(e->image->img_size_line), &(e->image->img_endian));
}
