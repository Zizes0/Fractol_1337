/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:56:59 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/05/19 22:26:22 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_tl *data)
{
	if (data->set == 0)
		return (1);
	data->mouse_x = (x - (WIDTH / 2.0)) / (WIDTH / 4.0);
	data->mouse_y = (y - (HEIGHT / 2.0)) / (HEIGHT / 4.0);
	render(data);
	return (0);
}

int	key_down(int keycode, void *param)
{
	if (keycode == 53)
		close_on(param);
	return (0);
}

int	close_on(void *p)
{
	(void)p;
	exit(1);
}

int	mouse_zoom(int button, int x, int y, t_tl *param)
{
	x = 0;
	y = x;
	if (button == 4)
	{
		param->zoom *= 1.05;
	}
	else if (button == 5)
	{
		param->zoom /= 1.05;
	}
	render(param);
	return (0);
}
