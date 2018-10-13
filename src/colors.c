/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:28:57 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 17:09:41 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_hsv	init_hsv(int h, int s, int v)
{
	t_hsv	hsv;

	hsv.h = h;
	hsv.s = s;
	hsv.v = v;
	return (hsv);
}

t_rgb	init_rgb(int h, int s, int v)
{
	t_rgb	hsv;

	hsv.r = h;
	hsv.g = s;
	hsv.b = v;
	return (hsv);
}

int		creatergb(t_rgb rgb)
{
	return ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	HELP;
	if (hsv.s == 0)
	{
		a[4] = hsv.v;
		a[5] = hsv.v;
		a[6] = hsv.v;
	}
	else
	{
		help1(a, hsv);
		if (a[0] == 0)
			help2(a, hsv);
		else if (a[0] == 1)
			help3(a, hsv);
		else if (a[0] == 2)
			help4(a, hsv);
		else if (a[0] == 3)
			help5(a, hsv);
		else if (a[0] == 4)
			help6(a, hsv);
		else
			help7(a, hsv);
	}
	HELPP;
	return (rgb);
}
