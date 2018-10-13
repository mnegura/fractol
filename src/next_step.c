/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:15 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 18:16:18 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	next_step_j(void)
{
	fr.julia.img = mlx_new_image(fr.julia.mlx, WIDTH, HEIGHT);
	fr.julia.str = mlx_get_data_addr(fr.julia.img, &fr.julia.bpp,
		&fr.julia.sline, &fr.julia.endian);
	julia();
	mlx_put_image_to_window(fr.julia.mlx, fr.julia.win, fr.julia.img, 0, 0);
	mlx_destroy_image(fr.julia.mlx, fr.julia.img);
}

void	next_step_m(void)
{
	fr.mandel.img = mlx_new_image(fr.mandel.mlx, WIDTH, HEIGHT);
	fr.mandel.str = mlx_get_data_addr(fr.mandel.img, &fr.mandel.bpp,
		&fr.mandel.sline, &fr.mandel.endian);
	mandelbrot();
	mlx_put_image_to_window(fr.mandel.mlx, fr.mandel.win, fr.mandel.img, 0, 0);
	mlx_destroy_image(fr.mandel.mlx, fr.mandel.img);
}

void	next_step_t(void)
{
	fr.titanic.img = mlx_new_image(fr.titanic.mlx, WIDTH, HEIGHT);
	fr.titanic.str = mlx_get_data_addr(fr.titanic.img, &fr.titanic.bpp,
		&fr.titanic.sline, &fr.titanic.endian);
	titanic();
	mlx_put_image_to_window(fr.titanic.mlx, fr.titanic.win,
		fr.titanic.img, 0, 0);
	mlx_destroy_image(fr.titanic.mlx, fr.titanic.img);
}

void	next_step_n(void)
{
	fr.newton.img = mlx_new_image(fr.newton.mlx, WIDTH, HEIGHT);
	fr.newton.str = mlx_get_data_addr(fr.newton.img, &fr.newton.bpp,
		&fr.newton.sline, &fr.newton.endian);
	newton();
	mlx_put_image_to_window(fr.newton.mlx, fr.newton.win, fr.newton.img, 0, 0);
	mlx_destroy_image(fr.newton.mlx, fr.newton.img);
}
