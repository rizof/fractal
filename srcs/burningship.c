/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
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
	cplx.c_r = iter->x / e->zoom + e->p0->x;
	cplx.c_i = iter->y / e->zoom + e->p0->y;
	cplx.z_r = iter->x / e->zoom + e->p0->x;
	cplx.z_i = iter->y / e->zoom + e->p0->y;
	while (cplx.z_r * cplx.z_r + cplx.z_i * cplx.z_i < 4
			&& ++i < e->iter)
	{
		if (cplx.z_r < 0)
			cplx.z_r = -cplx.z_r;
		if (cplx.z_i < 0)
			cplx.z_i = -cplx.z_i;
		tmp = cplx.z_r;
		cplx.z_r = cplx.z_r * cplx.z_r - cplx.z_i * cplx.z_i + cplx.c_r;
		cplx.z_i = 2 * cplx.z_i * tmp + cplx.c_i;
	}
	return (i);
}

void					burningship(t_mlx *e)
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
