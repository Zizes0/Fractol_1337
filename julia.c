/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:02:47 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/05/19 19:46:52 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, t_tl *data)
{
	int		i;
	double	zx;
	double	zy;
	double	temp;

	zx = x;
	zy = y;
	i = 0;
	while (i < ITER && check_module(zx, zy) <= 2.0)
	{
		temp = zx;
		zx = zx * zx - zy * zy + data->mouse_x;
		zy = 2 * temp * zy + data->mouse_y;
		i++;
	}
	return (i);
}

void	render_julia(t_tl *data)
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
			itr = julia((x - (WIDTH / 2.0)) / data->zoom, (y - (HEIGHT / 2.0))
					/ data->zoom, data) / ITER * 255;
			my_mlx_pixel_put(data, x, y, trgb(0, itr, itr, itr));
			x++;
		}
		y++;
	}
}
