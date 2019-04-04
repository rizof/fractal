/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		info(t_mlx *e)
{
	char *str;

	str = ft_itoa(e->iter);
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 520, 15, 0x00FFFFFF, "---- Fracal ----");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 55, 910, 0x00FFFFFF, "a = gauche");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 300, 910, 0x00FFFFFF, "d = droite");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 55, 930, 0x00FFFFFF, "w = haut");
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 300, 930, 0x00FFFFFF, "s = bas");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 910,
		0x00FFFFFF, "double clickG = zoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 930,
		0x00FFFFFF, "double clickD = dezoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 950,
		0x00FFFFFF, "c             = change color");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 600, 970,
		0x00FFFFFF, "iteration     =");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 760, 970,
		0x00FFFFFF, str);
	free(str);
}

void		function_color(t_mlx *e, int y, int y2, int x2)
{
	int x;

	x = 0;
	while (y < y2)
	{
		while (x < x2)
		{
			img_pixel_put(e, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
}

void		design_windows(t_mlx *e)
{
	int y;
	int x;

	y = 0;
	x = 0;
	e->design = 0x4A0404;
	function_color(e, 0, 100, 1200);
	e->design = 0x3B3B3B;
	function_color(e, 100, 103, 1200);
	function_color(e, 897, 900, 1200);
	e->design = 0x4A0404;
	function_color(e, 900, 1000, 1200);
	e->design = 0;
}

t_color		*color2(int iter, int iter_max, t_mlx *e, t_color *clr)
{
	if (e->color == 2)
	{
		clr->r = rand() % 10 + iter * iter_max;
		clr->g = rand() % 10 + iter * iter_max;
		clr->b = rand() % 10 + iter * iter_max;
	}
	else if (e->color == 3)
	{
		clr->r = sin(0.3 * (double)iter);
		clr->g = sin(0.3 * (double)iter + 3) * 127 + 128;
		clr->b = sin(0.3 * (double)iter + 3) * 127 + 128;
	}
	return (clr);
}

t_color		*color(int iter, int iter_max, t_mlx *e)
{
	if (iter == iter_max)
	{
		e->clr->r = 0;
		e->clr->g = 0;
		e->clr->b = 0;
	}
	else if (e->color == 1)
	{
		e->clr->r = (78 + iter * 2) % 255;
		e->clr->g = (20 + (iter * 4)) % 255;
		e->clr->b = (83 + (iter * 6)) % 255;
	}
	e->clr = color2(iter, iter_max, e, e->clr);
	return (e->clr);
}
