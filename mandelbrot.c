/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:49:30 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/05/19 20:05:59 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x, double y)
{
	int		i;
	double	zx;
	double	zy;
	double	temp;

	zx = 0;
	zy = 0;
	i = 0;
	while (i < ITER && check_module(zx, zy) <= 2.0)
	{
		temp = zx;
		zx = zx * zx - zy * zy + x;
		zy = 2 * temp * zy + y;
		i++;
	}
	return (i);
}

void	render_mandelbrot(t_tl *data)
{
	int	x;
	int	y;
	int	itr;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			itr = mandelbrot((x - (WIDTH / 2.0)) / data->zoom, (y - (HEIGHT
							/ 2.0)) / data->zoom) / ITER * 255;
			my_mlx_pixel_put(data, x, y, trgb(0, itr, itr, itr));
			x++;
		}
		y++;
	}
}
