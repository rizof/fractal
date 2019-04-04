/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouve_key(int keycode, t_mlx *e)
{
	if (keycode == 2)
	{
		e->p0->x -= 0.3;
		e->p1->x -= 0.3;
	}
	else if (keycode == 0)
	{
		e->p0->x += 0.3;
		e->p1->x += 0.3;
	}
	if (keycode == 1)
	{
		e->p0->y -= 0.3;
		e->p1->y -= 0.3;
	}
	else if (keycode == 13)
	{
		e->p0->y += 0.3;
		e->p1->y += 0.3;
	}
	if (keycode == 35)
		e->on_mouve = 1;
	if (keycode == 31)
		e->on_mouve = 0;
}

void	complx_key(int key, t_mlx *e)
{
	if (key == 123)
	{
		e->cplx->c_r += 0.007;
		e->cplx->c_i += 0.0027015;
	}
	if (key == 124)
	{
		e->cplx->c_r -= 0.007;
		e->cplx->c_i -= 0.0027015;
	}
}

int		deal_key(int key, t_mlx *e)
{
	int	step;

	if (key == 53)
		exit(EXIT_SUCCESS);
	step = 10;
	if (key == 126)
		e->iter += step;
	else if (key == 125)
		e->iter -= step;
	if (e->iter < 20)
		e->iter = 20;
	if (key == 8)
	{
		e->color += 1;
		if (e->color == 4)
			e->color = 1;
	}
	complx_key(key, e);
	mouve_key(key, e);
	routage(e);
	return (0);
}
