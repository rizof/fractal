/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:47 by kecosmon          #+#    #+#             */
/*   Updated: 2018/09/11 15:37:50 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# define WIDTH 1200
# define HEIGHT 1000
# define USAGE "usage : ./fracol  mandelbrot | julia | burningship"

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_cplx
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_cplx;

typedef struct		s_coor
{
	double			x;
	double			y;
}					t_coor;

typedef struct		s_image
{
	void			*img;
	char			*img_data;
	int				img_bpp;
	int				img_size_line;
	int				img_endian;
}					t_image;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*image;
	int				iter;
	double			zoom;
	int				design;
	t_coor			*p0;
	t_coor			*p1;
	t_cplx			*cplx;
	t_color			*clr;
	int				fractal;
	int				color;
	int				zoomplus;
	int				dezoom;
	double			x_real;
	double			y_real;
	int				on_mouve;
}					t_mlx;

t_color				*color(int iter, int iter_max, t_mlx *e);
int					init_fract(const char *fract, t_mlx *e);
void				julia(t_mlx *mlx);
void				mandelbrot(t_mlx *mlx);
void				put_pixel(t_mlx *mlx, t_coor *pixel, int color);
void				burningship(t_mlx *mlx);
void				clear_image(t_mlx *e);
void				img_pixel_put(t_mlx *e, int x, int y, t_color *clr);
void				mouve_key(int keycode, t_mlx *e);
int					deal_key(int key, t_mlx *e);
int					deal_hook(void *param);
void				design_windows(t_mlx *e);
int					error(char *str);
int					mouse_moove(int x, int y, void *p);
int					mouse_hook(int button, int x, int y, t_mlx *mlx);
void				push_fract(t_mlx *e);
void				info(t_mlx *e);
int					mouse_hook(int button, int x, int y, t_mlx *mlx);
void				routage(t_mlx *e);
int					ft_close(void);
void				center(t_mlx *e);
void				malloc_struc(t_mlx *e);

#endif
