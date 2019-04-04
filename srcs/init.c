/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		init_mandelbrot(t_mlx *e)
{
	e->iter = 200;
	e->p0->x = -2.1;
	e->p1->x = 0.6;
	e->p0->y = -1.2;
	e->p1->y = 1.2;
	e->zoom = 204;
	e->cplx->c_r = 0;
	e->cplx->c_i = 0;
}

static void		init_julia(t_mlx *e)
{
	e->iter = 70;
	e->p0->x = -1;
	e->p1->x = 0.9;
	e->p0->y = -1.1;
	e->p1->y = 0.9;
	e->zoom = 282;
	e->cplx->c_r = 0.285;
	e->cplx->c_i = 0.01;
}

static void		init_burningship(t_mlx *e)
{
	e->iter = 150;
	e->p0->x = -1;
	e->p1->x = 1.5;
	e->p0->y = -1.1;
	e->p1->y = 0.8;
	e->zoom = 272;
	e->cplx->c_r = 0.285;
	e->cplx->c_i = 0.01;
}

int				init_fract(const char *fract, t_mlx *e)
{
	if (!ft_strcmp(fract, "julia"))
	{
		init_julia(e);
		return (1);
	}
	else if (!ft_strcmp(fract, "mandelbrot"))
	{
		init_mandelbrot(e);
		return (2);
	}
	else if (!ft_strcmp(fract, "burningship"))
	{
		init_burningship(e);
		return (3);
	}
	else
		return (0);
}
