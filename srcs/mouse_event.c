/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse(t_mlx *e, int x, int y, int button)
{
	if (x > 0 && y > 0)
	{
		e->x_real = (x / e->zoom) + e->p0->x;
		e->y_real = (y / e->zoom) + e->p0->y;
		if (button == 4 || e->zoomplus == 2 || button == 7)
		{
			e->zoom *= 2.1;
			e->p0->x = e->x_real - (x / e->zoom);
			e->p0->y = e->y_real - (y / e->zoom);
			e->iter++;
		}
		if (button == 5 || e->dezoom == 2 || button == 6)
		{
			e->zoom /= 2.1;
			e->p0->x = e->x_real - (x / e->zoom);
			e->p0->y = e->y_real - (y / e->zoom);
			e->iter--;
		}
		if (e->zoomplus == 2 || e->dezoom == 2)
		{
			e->zoomplus = 0;
			e->dezoom = 0;
		}
	}
}

int		mouse_hook(int button, int x, int y, t_mlx *e)
{
	if (button == 1)
		e->zoomplus++;
	if (button == 2)
		e->dezoom++;
	mouse(e, x, y, button);
	routage(e);
	return (0);
}

int		mouse_moove(int x, int y, void *p)
{
	t_mlx	*e;

	e = (t_mlx*)p;
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	e->cplx->c_r = -0.7 + (double)x / 1000;
	e->cplx->c_i = 0.27015 + (double)y / 1000;
	routage(e);
	return (0);
}
