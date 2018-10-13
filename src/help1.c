/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:13:30 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/13 17:13:43 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	help1(double *a, t_hsv hsv)
{
	a[7] = hsv.h * 6;
	if (a[7] == 6)
		a[7] = 0;
	a[0] = (int)a[7];
	a[1] = hsv.v * (1 - hsv.s);
	a[2] = hsv.v * (1 - hsv.s * (a[7] - a[0]));
	a[3] = hsv.v * (1 - hsv.s * (1 - (a[7] - a[0])));
}

void	help2(double *a, t_hsv hsv)
{
	a[4] = hsv.v;
	a[5] = a[3];
	a[6] = a[1];
}

void	help3(double *a, t_hsv hsv)
{
	a[4] = a[2];
	a[5] = hsv.v;
	a[6] = a[1];
}

void	help4(double *a, t_hsv hsv)
{
	a[4] = a[1];
	a[5] = hsv.v;
	a[6] = a[3];
}

void	help5(double *a, t_hsv hsv)
{
	a[4] = a[1];
	a[5] = a[2];
	a[6] = hsv.v;
}
