/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:56:43 by mnegura           #+#    #+#             */
/*   Updated: 2017/04/15 20:17:28 by mnegura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define WIDTH 700
# define HEIGHT 500
# define MAXITER 200
# define HZ t_fract	fr;

# define MSET  int maxi; int row; int col; int i; double c_re; double c_im;
# define MSETT double x; double y; double x_new; int color; maxi = 700;

# define JSET double new_re; double new_im;
# define JSETT double old_re;double old_im; int i; int y; int x;
# define JSETTT y = -1;

# define TSET double new_re; double new_im; TSETT; TSETTT;
# define TSETT double old_re;double old_im; int i; int maxi; int y; int x;
# define TSETTT y = -1; double c_re; double c_im; maxi = 500;
# define TSETTTT new_re = 0; new_im = 0; old_re = 0; old_im = 0;

# define NSET double new_re; double new_im; NSETT; NSETTT;
# define NSETT double old_re;double old_im; int maxi; int i; int y; int x;
# define NSETTT maxi = 300; y = -1;

# define HELP t_rgb	rgb; double	a[8];
# define HELPP rgb.r = a[4] * 255; rgb.g = a[5] * 255; rgb.b = a[6] * 255;

# define TH1 {fr.th1 = 1; fr.th2 = 0; fr.th3 = 0; TH11;}
# define TH11 {fr.th4 = 0;fr.th5 = 0; fr.m = 1; expose_hook();}
# define TH2 {fr.th1 = 0; fr.th2 = 1; fr.th3 = 0; TH22;}
# define TH22 {fr.th4 = 0;fr.th5 = 0;fr.m = 3; expose_hook();}
# define TH3 {fr.th1 = 0; fr.th2 = 0; fr.th3 = 1; TH33;}
# define TH33 {fr.th4 = 0;fr.th5 = 0;fr.m = 4; expose_hook();}
# define TH4 {fr.th1 = 0; fr.th2 = 0; fr.th3 = 0; TH44;}
# define TH44 {fr.th4 = 1;fr.th5 = 0;fr.m = 5; expose_hook();}
# define TH5 {fr.th1 = 0; fr.th2 = 0; fr.th3 = 0; TH55;}
# define TH55 {fr.th4 = 0;fr.th5 = 1;fr.m = 6; expose_hook();}

# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L << 6)

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct		s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

typedef struct		s_mandel
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*str;
	int				bpp;
	int				endian;
	int				sline;
}					t_mandel;

typedef struct		s_titanic
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*str;
	int				bpp;
	int				endian;
	int				sline;
}					t_titanic;

typedef struct		s_mouse
{
	int				x;
	int				y;
	int				key_code;
}					t_mouse;

typedef struct		s_color
{
	int				theme1[16];
	int				theme2[19];
	int				theme3[16];
	int				theme4[16];
	int				theme5[16];
}					t_color;

typedef struct		s_julia
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*str;
	int				bpp;
	int				endian;
	int				sline;
	int				j_stop;
	double			c_re;
	double			c_im;
	int				maxi;
}					t_julia;

typedef struct		s_newton
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*str;
	int				bpp;
	int				endian;
	int				sline;
	double			c_re;
	double			c_im;
	int				j_stop;
}					t_newton;

typedef struct		s_fract
{
	void			*mlx;
	int				juliaa;
	int				newtonn;
	int				mandelbrot;
	int				titan;
	int				originx;
	int				originy;
	double			zoom;
	double			h;
	double			s;
	double			v;
	t_mandel		mandel;
	t_mouse			mouse;
	t_color			color;
	t_julia			julia;
	t_newton		newton;
	t_titanic		titanic;
	int				th1;
	int				th2;
	int				th3;
	int				th4;
	int				th5;
	int				m;
	double			mvx;
	double			mvy;
}					t_fract;

t_rgb				init_rgb(int h, int s, int v);
int					ft_motion(int x, int y, t_fract *fr);
void				ft_init_mandel(void);
void				expose_hook(void);
int					next_step(void);
int					ft_hook(int m_code, int x, int y, t_fract *fr);
int					key_hook(int key);
void				mandelbrot(void);
void				put_pixel_n(int x, int y, int color);
t_rgb				hsv_to_rgb(t_hsv hsv);
int					creatergb(t_rgb rgb);
t_hsv				init_hsv(int h, int s, int v);
void				julia(void);
void				newton(void);
void				put_pixel_j(int x, int y, int color);
void				put_pixel_m(int x, int y, int color);
void				put_pixel_t(int x, int y, int color);
void				help1(double *a, t_hsv hsv);
void				help2(double *a, t_hsv hsv);
void				help3(double *a, t_hsv hsv);
void				help4(double *a, t_hsv hsv);
void				help5(double *a, t_hsv hsv);
void				help6(double *a, t_hsv hsv);
void				help7(double *a, t_hsv hsv);
void				next_step_n(void);
void				next_step_j(void);
void				next_step_m(void);
void				ft_first_j(void);
void				ft_first_m(void);
void				ft_first_n(void);
void				ft_first(void);
void				ft_help_put_pixel_n(int x, int y, int i);
void				ft_help_put_pixel_j(int x, int y, int i);
void				ft_help_put_pixel_t(int x, int y, int i);
void				ft_th1(void);
void				ft_th2(void);
void				ft_th3(void);
void				ft_th4(void);
void				ft_th5(void);
void				ft_init(void);
void				titanic(void);
void				next_step_t(void);
HZ;
#endif
