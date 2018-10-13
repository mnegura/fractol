/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:59:24 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 18:00:00 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		ft_help_put_pixel_n(int x, int y, int i)
{
	if (fr.th1 == 1 || fr.th1 == 2)
		put_pixel_n(x, y, fr.color.theme1[(int)sqrt(i)
					* (int)log2(i) % 7]);
	if (fr.th2 == 1)
		put_pixel_n(x, y, fr.color.theme2[(int)sqrt(i)
					* (int)log2(i) % 15]);
	if (fr.th3 == 1)
		put_pixel_n(x, y, fr.color.theme3[(int)sqrt(i)
					* (int)log2(i) % 15]);
	if (fr.th4 == 1)
		put_pixel_n(x, y, fr.color.theme4[(int)((int)sqrt(i)
					* (int)log2(i) % 49 * 1.5)]);
	if (fr.th5 == 1)
		put_pixel_n(x, y, fr.color.theme5[(int)((int)sqrt(i)
					* (int)log2(i) % 49 * 1.5)]);
}

void		ft_help_put_pixel_j(int x, int y, int i)
{
	if (fr.th1 == 1 || fr.th1 == 2)
		put_pixel_j(x, y, fr.color.theme1[(int)sqrt(i)
					* (int)log2(i) % 69]);
	if (fr.th2 == 1)
		put_pixel_j(x, y, fr.color.theme2[(int)sqrt(i)
					* (int)log2(i) % 27]);
	if (fr.th3 == 1)
		put_pixel_j(x, y, fr.color.theme3[(int)sqrt(i)
					* (int)log2(i) % 27]);
	if (fr.th4 == 1)
		put_pixel_j(x, y, fr.color.theme4[(int)sqrt(i)
					* (int)log2(i) % 32]);
	if (fr.th5 == 1)
		put_pixel_j(x, y, fr.color.theme5[i % 19]);
}

void		ft_help_put_pixel_t(int x, int y, int i)
{
	if (fr.th1 == 1 || fr.th1 == 2)
		put_pixel_t(x, y, fr.color.theme1[(int)sqrt(i)
					* (int)log2(i) % 69]);
	if (fr.th2 == 1)
		put_pixel_t(x, y, fr.color.theme2[(int)sqrt(i)
					* (int)log2(i) % 27]);
	if (fr.th3 == 1)
		put_pixel_t(x, y, fr.color.theme3[(int)sqrt(i)
					* (int)log2(i) % 27]);
	if (fr.th4 == 1)
		put_pixel_t(x, y, fr.color.theme4[(int)sqrt(i)
					* (int)log2(i) % 32]);
	if (fr.th5 == 1)
		put_pixel_t(x, y, fr.color.theme5[i % 19]);
}
