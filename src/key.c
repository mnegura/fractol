/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:51:17 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 17:40:00 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	key_hook2(int key)
{
	if (key == 125)
	{
		fr.mvy -= 5 / fr.zoom;
		expose_hook();
	}
	if (key == 126)
	{
		fr.mvy += 5 / fr.zoom;
		expose_hook();
	}
	if (key == 123)
	{
		fr.mvx += 5 / fr.zoom;
		expose_hook();
	}
	if (key == 124)
	{
		fr.mvx -= 5 / fr.zoom;
		expose_hook();
	}
}

int		key_hook(int key)
{
	if (key == 53)
		exit(0);
	if (key == 18)
		TH1;
	if (key == 19)
		TH2;
	if (key == 20)
		TH3;
	if (key == 21)
		TH4;
	if (key == 23)
		TH5;
	if (key == 38)
		fr.julia.j_stop += 1;
	if (key == 15)
		fr.newton.j_stop += 1;
	if (key == 29)
	{
		ft_init();
		expose_hook();
	}
	key_hook2(key);
	return (0);
}

void	expose_hook(void)
{
	if (fr.juliaa == 1)
	{
		mlx_clear_window(fr.julia.mlx, fr.julia.win);
		next_step();
	}
	if (fr.mandelbrot == 1)
	{
		mlx_clear_window(fr.mandel.mlx, fr.mandel.win);
		next_step();
	}
	if (fr.newtonn == 1)
	{
		mlx_clear_window(fr.newton.mlx, fr.newton.win);
		next_step();
	}
	if (fr.titan == 1)
	{
		mlx_clear_window(fr.titanic.mlx, fr.titanic.win);
		next_step();
	}
}

int		ft_motion(int x, int y, t_fract *fr)
{
	if (fr->julia.j_stop % 2 == 1)
	{
		fr->julia.c_re = (double)x / (double)WIDTH * 4 - 5.9;
		fr->julia.c_im = (double)y / (double)HEIGHT * 4 - 2.1;
		julia();
		expose_hook();
	}
	if (fr->newton.j_stop % 2 == 1)
	{
		fr->newton.c_re = (double)x / (double)WIDTH * 4 - 5.9;
		fr->newton.c_im = (double)y / (double)HEIGHT * 4 - 2.1;
		newton();
		expose_hook();
	}
	return (0);
}

int		ft_hook(int m_code, int x, int y, t_fract *fr)
{
	if (m_code == 4)
	{
		fr->originx = x - (x - fr->originx) * 1.5;
		fr->originy = y - (y - fr->originy) * 1.5;
		fr->zoom *= 1.5;
		expose_hook();
	}
	if (m_code == 5)
	{
		fr->julia.maxi--;
		fr->originx = x - (x - fr->originx) / 1.5;
		fr->originy = y - (y - fr->originy) / 1.5;
		fr->zoom /= 1.5;
		expose_hook();
	}
	return (0);
}
