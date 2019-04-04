/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int				iterate(t_mlx *e, t_coor *iter)
{
	int					i;
	t_cplx				cplx;
	double				tmp;

	i = -1;
	cplx.z_r = e->cplx->c_r;
	cplx.z_i = e->cplx->c_i;
	cplx.c_r = iter->x / e->zoom + e->p0->x;
	cplx.c_i = iter->y / e->zoom + e->p0->y;
	while (cplx.z_r * cplx.z_r + cplx.z_i * cplx.z_i < 4
			&& ++i < e->iter)
	{
		tmp = cplx.z_r;
		cplx.z_r = cplx.z_r * cplx.z_r - cplx.z_i * cplx.z_i + cplx.c_r;
		cplx.z_i = 2 * cplx.z_i * tmp + cplx.c_i;
	}
	return (i);
}

void					mandelbrot(t_mlx *e)
{
	t_coor				iter;

	iter.x = 0;
	while (iter.x < WIDTH)
	{
		iter.y = 0;
		while (iter.y < HEIGHT)
		{
			img_pixel_put(e, iter.x, iter.y,\
				color(iterate(e, &iter), e->iter, e));
			iter.y++;
		}
		iter.x++;
	}
}
