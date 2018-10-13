/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marina.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:49:21 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/15 20:40:11 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			next_step(void)
{
	// int	i;

	// i = -1;
	if (fr.juliaa == 1)
		next_step_j();
	if (fr.mandelbrot == 1)
		next_step_m();
	if (fr.newtonn == 1)
		next_step_n();
	if (fr.titan == 1)
		next_step_t();
	return (0);
}

void		ft_init(void)
{
	fr.zoom = HEIGHT / 4;
	fr.originx = WIDTH / 2.0;
	fr.originy = HEIGHT / 2.0;
	fr.julia.j_stop = 0;
	fr.newton.j_stop = 0;
	fr.julia.c_re = -0.7;
	fr.julia.c_im = 0.27015;
	fr.julia.maxi = 300;
	fr.newton.c_re = -0.123;
	fr.newton.c_im = 0.745;
	fr.mvx = 0;
	fr.mvy = 0;
	fr.th1 = 2;
	fr.th2 = 0;
	fr.th3 = 0;
	fr.th4 = 0;
	fr.th5 = 0;
	fr.m = 1;
	ft_th1();
	ft_th2();
	ft_th3();
	ft_th4();
	ft_th5();
}

void		menu(void)
{
	ft_putstr("\n\n\n------------------------------\n\n");
	ft_putstr("Hello ;3 \nJ = motion Julia\nR = motion Rabbit\n\n");
	ft_putstr("Themes = 1..5\n\n");
	ft_putstr("ARROW UP = Up\n");
	ft_putstr("ARROW DOWN = Down\n");
	ft_putstr("ARROW LEFT = Left\nARROW RIGHT = Right\n\n");
	ft_putstr("Reset = 0\n\n");
	ft_putstr("scroll in = zoom in\nscroll out = zoom out\n\n");
	ft_putstr("ESC for exit");
	ft_putstr("\n\n------------------------------\n");
}

t_fract		who_are_you(char *str)
{
	t_fract fr;

	if (str[0] == 'm' || str[0] == 'M')
		fr.mandelbrot = 1;
	if (str[0] == 'j' || str[0] == 'J')
		fr.juliaa = 1;
	if (str[0] == 'n' || str[0] == 'N')
		fr.newtonn = 1;
	if (str[0] == 't' || str[0] == 'T')
		fr.titan = 1;
	return (fr);
}

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
		while (++i < ac)
		{
			menu();
			fr = who_are_you(av[i]);
			ft_init();
			ft_first();
		}
	else
		ft_putstr("usage: ./fractol   fractolname\n");
}
