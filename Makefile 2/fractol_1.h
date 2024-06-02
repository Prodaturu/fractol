/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:14:00 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/19 13:19:36 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1080
# define HEIGHT 1080
# define ZOOM_VALUE 0.1
# define MI 100

/**
 * @struct MandelbrotParams
 * @brief Represents the parameters for the Mandelbrot fractal.
 * includes range of x &s,&s,of iterations, color, image & mlx pointers.
 * Additionally, it includes a.
 
 * Holds parameters required to generate & render fractal.
 * - xmin: the minimum x value
 * - xmax: the maximum x value
 * - ymin: the minimum y value
 * - ymax: the maximum y value
 * - re: the real part of the constant 'c'
 * - im: the imaginary part of the constant 'c'
 * - cre: the real part of the current complex number 'z'
 * - cim: the imaginary part of the current complex number 'z'
 * - iterations: the number of iterations
 * - zre: temporary variable for the real part of 'z'
 * - zim: temporary variable for the imaginary part of 'z'
 * - zretemp: temporary variable for the real part of 'z'
 * - clr: the color of the fractal
 * - image: pointer to the image
 * - mlx: pointer to the MLX42 library
 * - giyali: flag indicating whether the fractal should be drawn
 **/

typedef struct s_fractal
{
	mlx_image_t		*bomma;
	mlx_t			*mlx;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			cre;
	double			cim;
	double			re;
	double			im;
	double			zre;
	double			zim;
	int32_t			xpos;
	int32_t			ypos;
	int				itr;
	int				clr;
	int				giyali;
}					t_fractal;

void	giyi_julia(void *param);
void	giyi_mandel(void *param);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
double	ft_atof(char *num_str);
void	moving(mlx_key_data_t key, void *param);
int		julia_on(double fr, double fi, double cr, double ci);
int		pixel_clr(int itr);
void	mandle_on(t_fractal *f, double hi, double vi);
void	mandel_vals(t_fractal *f);
void	giyi_burning_ship(void *param);
void	burning_ship_on(t_fractal *f, double hi, double vi);
void	burn_the_ship(void *mlx, t_fractal *f);
void	mandel_is_hooked(void *mlx, t_fractal *f);

#endif
