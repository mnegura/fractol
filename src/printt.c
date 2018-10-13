/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 19:14:32 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/15 19:14:35 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		put_pixel_t(int x, int y, int color)
{
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = x * 4;
	offset += y * fr.titanic.sline;
	*(int*)(fr.titanic.str + offset) = color;
}

void		put_pixel_j(int x, int y, int color)
{
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = x * 4;
	offset += y * fr.julia.sline;
	*(int*)(fr.julia.str + offset) = color;
}

void		put_pixel_m(int x, int y, int color)
{
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = x * 4;
	offset += y * fr.mandel.sline;
	*(int*)(fr.mandel.str + offset) = color;
}

void		put_pixel_n(int x, int y, int color)
{
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = x * 4;
	offset += y * fr.newton.sline;
	*(int*)(fr.newton.str + offset) = color;
}
