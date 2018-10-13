/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:15:04 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 18:15:42 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		ft_first_j(void)
{
	next_step();
	mlx_expose_hook(fr.julia.win, next_step, &fr);
	mlx_key_hook(fr.julia.win, key_hook, &fr);
	mlx_mouse_hook(fr.julia.win, ft_hook, &fr);
	mlx_hook(fr.julia.win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, &fr);
	mlx_loop(fr.julia.mlx);
}

void		ft_first_m(void)
{
	next_step();
	mlx_expose_hook(fr.mandel.win, next_step, &fr);
	mlx_key_hook(fr.mandel.win, key_hook, &fr);
	mlx_mouse_hook(fr.mandel.win, ft_hook, &fr);
	mlx_loop(fr.mandel.mlx);
}

void		ft_first_n(void)
{
	next_step();
	mlx_expose_hook(fr.newton.win, next_step, &fr);
	mlx_key_hook(fr.newton.win, key_hook, &fr);
	mlx_mouse_hook(fr.newton.win, ft_hook, &fr);
	mlx_hook(fr.newton.win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, &fr);
	mlx_loop(fr.newton.mlx);
}

void		ft_first_t(void)
{
	next_step();
	mlx_expose_hook(fr.titanic.win, next_step, &fr);
	mlx_key_hook(fr.titanic.win, key_hook, &fr);
	mlx_mouse_hook(fr.titanic.win, ft_hook, &fr);
	mlx_loop(fr.titanic.mlx);
}

void		ft_first(void)
{
	if (fr.juliaa == 1)
	{
		fr.julia.mlx = mlx_init();
		fr.julia.win = mlx_new_window(fr.julia.mlx, WIDTH, HEIGHT, "Julia");
		ft_first_j();
	}
	if (fr.mandelbrot == 1)
	{
		fr.mandel.mlx = mlx_init();
		fr.mandel.win = mlx_new_window(fr.mandel.mlx, WIDTH, HEIGHT,
				"Mandelbrot");
		ft_first_m();
	}
	if (fr.newtonn == 1)
	{
		fr.newton.mlx = mlx_init();
		fr.newton.win = mlx_new_window(fr.newton.mlx, WIDTH, HEIGHT, "Rabbit");
		ft_first_n();
	}
	if (fr.titan == 1)
	{
		fr.titanic.mlx = mlx_init();
		fr.titanic.win = mlx_new_window(fr.titanic.mlx, WIDTH, HEIGHT, "Titan");
		ft_first_t();
	}
}
