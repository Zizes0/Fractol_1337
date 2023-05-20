/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:15:12 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/05/19 19:57:01 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t			i;
	unsigned char	*l1;
	unsigned char	*l2;

	l1 = (unsigned char *)s1;
	l2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (l1[i] == l2[i] && i < (n - 1) && l1[i] != 0 && l2[i] != 0)
		i++;
	return (l1[i] - l2[i]);
}

int	arg_count(int argc)
{
	if (argc > 2)
		return (write(2,
				"ERROR : TOO MUCH ARGUMENTS!\nUse: mandelbrot or julia", 52));
	else if (argc < 2)
		return (write(2,
				"ERROR : NOT ENOUGH ARGUMENTS!\nUse: mandelbrot or julia", 54));
	else if (argc == 2)
		return (1);
	return (0);
}

void	arg_check(const char *str, t_tl *data)
{
	int	i;

	i = 0;
	if (strcmp("mandelbrot", str) == 0)
		data->set = 0;
	else if (strcmp("julia", str) == 0)
		data->set = 1;
	else
	{
		write(2, "Unavailable parameter\nuse: mandelbrot or julia", 47);
		exit(1);
	}
}

void	render(t_tl *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_clear_window(data->mlx, data->win);
	if (data->set == 0)
		render_mandelbrot(data);
	else if (data->set == 1)
		render_julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
