/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:14:55 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 17:38:35 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(void)
{
	JSET;
	JSETT;
	JSETTT;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			new_re = 250.5 * (x - fr.originx) /
				(fr.zoom * 0.5 * WIDTH) + fr.mvx;
			new_im = 250.5 * (y - fr.originy) /
				(fr.zoom * 0.5 * HEIGHT) + fr.mvy;
			i = -1;
			while (++i < fr.julia.maxi)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + fr.julia.c_re;
				new_im = 2 * old_re * old_im + fr.julia.c_im;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			ft_help_put_pixel_j(x, y, i);
		}
	}
}

void	newton(void)
{
	NSET;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			new_re = 250.5 * (x - fr.originx) /
				(fr.zoom * 0.5 * WIDTH) + fr.mvx;
			new_im = 250.5 * (y - fr.originy) /
				(fr.zoom * 0.5 * HEIGHT) + fr.mvy;
			i = -1;
			while (++i < maxi)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im +
					fr.newton.c_re;
				new_im = 2 * old_re * old_im + fr.newton.c_im;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			ft_help_put_pixel_n(x, y, i);
		}
	}
}
