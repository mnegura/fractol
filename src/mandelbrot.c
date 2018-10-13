/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:40:39 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 17:48:48 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_color(int i, double x, double y, int maxi)
{
	double	z;
	int		brightness;
	int		color;

	if (i == maxi)
		color = creatergb(hsv_to_rgb(init_hsv(0, 0, 0)));
	else
	{
		z = sqrt(x * x + y * y);
		brightness = 256. * log2(1.75 + i - log2(log2(z))) /
			log2((double)(maxi));
		if (brightness + 100 > 256)
			color = creatergb(init_rgb(brightness, brightness, 255));
		else
			color = creatergb(init_rgb(brightness, brightness +
				138 * fr.m, 255));
	}
	return (color);
}

void	mandelbrot(void)
{
	MSET;
	MSETT;
	row = -1;
	while (++row < WIDTH)
	{
		col = -1;
		while (++col < HEIGHT)
		{
			c_re = (row - fr.originx) / (fr.zoom / 9) + (fr.mvx * 3);
			c_im = (col - fr.originy) / (fr.zoom / 9) + (fr.mvy * 3);
			x = c_re;
			y = c_im;
			i = 0;
			while (x * x + y * y <= 4 && i < maxi)
			{
				x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
				i += 4;
			}
			color = ft_color(i, x, y, maxi);
			put_pixel_m(row, col, color);
		}
	}
}

void	titanic(void)
{
	TSET;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c_re = 250.5 * (x - fr.originx) /
				(fr.zoom * 0.5 * WIDTH) + fr.mvx;
			c_im = 250.5 * (y - fr.originy) /
				(fr.zoom * 0.5 * HEIGHT) + fr.mvy;
			TSETTTT;
			i = -1;
			while (++i < maxi)
			{
				old_re = fabs(new_re);
				old_im = fabs(new_im);
				new_re = old_re * old_re - old_im * old_im + c_re;
				new_im = 2 * old_re * old_im + c_im;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			ft_help_put_pixel_t(x, y, i);
		}
	}
}
