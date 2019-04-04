/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		error(char *str)
{
	ft_putendl(str);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	routage(t_mlx *e)
{
	push_fract(e);
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img, 0, 0);
	info(e);
}

void	center(t_mlx *e)
{
	mouve_key(2, e);
	mouve_key(2, e);
	mouve_key(2, e);
	mouve_key(2, e);
	mouve_key(1, e);
	mouve_key(1, e);
	if (e->fractal != 1)
	{
		mouve_key(1, e);
		mouve_key(1, e);
	}
}

void	malloc_struc(t_mlx *e)
{
	e->image = malloc(sizeof(t_image));
	e->image = ft_memset(e->image, 0, sizeof(e->image));
	e->p0 = malloc(sizeof(t_coor));
	e->p0 = ft_memset(e->p0, 0, sizeof(e->p0));
	e->p1 = malloc(sizeof(t_coor));
	e->p1 = ft_memset(e->p1, 0, sizeof(e->p1));
	e->cplx = malloc(sizeof(t_cplx));
	e->cplx = ft_memset(e->cplx, 0, sizeof(e->cplx));
	e->clr = malloc(sizeof(t_color));
	e->clr = ft_memset(e->clr, 0, sizeof(e->clr));
	e->design = 0;
	e->color = 1;
}
