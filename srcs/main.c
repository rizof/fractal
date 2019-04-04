/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:17 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:18 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	push_fract(t_mlx *e)
{
	clear_image(e);
	if (e->fractal == 1)
		julia(e);
	if (e->fractal == 2)
		mandelbrot(e);
	if (e->fractal == 3)
		burningship(e);
	design_windows(e);
}

int		expose_hook(void *param)
{
	t_mlx *e;

	e = (t_mlx *)param;
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	design_windows(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img,
	0, 0);
	info(e);
	return (1);
}

void	fractal(t_mlx *e)
{
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "FRACTOL_RIZOF");
	e->image->img = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->image->img_data = mlx_get_data_addr(e->image->img, &(e->image->img_bpp),\
	&(e->image->img_size_line), &(e->image->img_endian));
	mlx_expose_hook(e->win_ptr, expose_hook, e);
	push_fract(e);
	mlx_mouse_hook(e->win_ptr, mouse_hook, e);
	mlx_key_hook(e->win_ptr, deal_key, e);
	if (e->fractal == 1)
		mlx_hook(e->win_ptr, 6, 1L < 6, mouse_moove, (void*)e);
	mlx_hook(e->win_ptr, 17, 0L, ft_close, e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img, 0, 0);
	info(e);
	mlx_loop(e->mlx_ptr);
}

int		main(int ac, char const *av[])
{
	t_mlx	e;

	malloc_struc(&e);
	if (ac == 2)
	{
		if ((e.fractal = init_fract(av[1], &e)) == 0)
			return (error(USAGE));
	}
	else
		return (error(USAGE));
	if ((e.mlx_ptr = mlx_init()) == NULL)
		return (error("init error"));
	e.design = 0;
	e.color = 1;
	center(&e);
	fractal(&e);
	return (0);
}
