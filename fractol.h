/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:49:44 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/05/19 20:06:20 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define ITER 40.0

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_tl
{
	void	*mlx;
	void	*win;
	int		set;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	mouse_x;
	double	mouse_y;
	double	zoom;
}			t_tl;

int			julia(double x, double y, t_tl *data);
int			mandelbrot(double x, double y);
void		render_julia(t_tl *data);
void		render_mandelbrot(t_tl *data);
int			mouse_zoom(int button, int x, int y, t_tl *param);
int			mouse_move(int x, int y, t_tl *data);
double		check_module(double x, double y);
int			trgb(int t, int r, int g, int b);
void		render(t_tl *data);
void		my_mlx_pixel_put(t_tl *data, int x, int y, int color);
void		arg_check(const char *str, t_tl *data);
int			arg_count(int argc);
int			close_on(void *p);
int			key_down(int keycode, void *param);

#endif