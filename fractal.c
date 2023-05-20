/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:15:08 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/05/19 19:23:30 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_tl *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	check_module(double x, double y)
{
	return (sqrt(x * x + y * y));
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(int argc, char const *argv[])
{
	t_tl	alpha;

	if (arg_count(argc) == 1)
	{
		arg_check(argv[1], &alpha);
		alpha.zoom = 200.0;
		alpha.mlx = mlx_init();
		alpha.win = mlx_new_window(alpha.mlx, WIDTH, HEIGHT, "fractol");
		render(&alpha);
		mlx_hook(alpha.win, 6, 0, mouse_move, &alpha);
		mlx_hook(alpha.win, 17, 0, close_on, &alpha);
		mlx_hook(alpha.win, 2, 0, key_down, &alpha);
		mlx_mouse_hook(alpha.win, mouse_zoom, &alpha);
		mlx_loop(alpha.mlx);
	}
}
