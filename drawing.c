/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:22:23 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/19 13:46:29 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

// void	mandel_vals(t_fractal *f)
// {
// 	f->zim = 2 * f->zre * f->zim + f->cim;
// 	f->zre = f->re;
// 	f->re = f->zre * f->zre - f->zim * f->zim + f->cre;
// 	f->itr++;
// }

void mandel_vals(t_fractal *f) {
  double temp;

  temp = f->zre * f->zre - f->zim * f->zim + f->cre;
  f->zim = 2 * f->zre * f->zim + f->cim;
  f->zre = temp;
  f->itr++;
}

/**
 * zr = (fr * fr) - (fi * fi) + cr;
 * fi = 2 * (fr * fi) + ci;
 * The above two are calculations (z = z^2 + c) for the Julia fractal.
 * zr is the real part of the complex number z
 * fi is the imaginary part of the complex number z
 * since z^2 = (a + bi)^2 = a^2 - b^2 + 2abi
 * zr = (fr * fr) - (fi * fi) + cr;
 * fi = 2 * (fr * fi) + ci;
 */

int julia_on(double fr, double fi, double cr, double ci) {
  int iters;
  double temp;

  iters = 0;
  temp = 0.0;
  while (iters < MI && (fi * fi + fr * fr) <= 4) {
    temp = (fr * fr) - (fi * fi) + cr;
    fi = (2 * fr * fi) + ci;
    fr = temp;
    iters++;
  }
  return (iters);
}

void mandle_on(t_fractal *f, double hi, double vi) {
  f->cre = f->xmin + hi / f->bomma->width * (f->xmax - f->xmin);
  f->cim = f->ymin + vi / f->bomma->height * (f->ymax - f->ymin);
  f->re = f->cre;
  f->im = f->cim;
  f->itr = 0;
  f->zre = 0.0;
  f->zim = 0.0;
}

void giyi_mandel(void *param) {
  double hi;
  double vi;
  t_fractal *f;

  f = (t_fractal *)param;
  vi = 0.0;
  if (f->giyali == 1) {
    while (++vi < f->bomma->height) {
      hi = 0.0;
      while (++hi < f->bomma->width) {
        mandle_on(f, hi, vi);
        while (f->itr < MI && (f->zre * f->zre + f->zim * f->zim) <= 4)
          mandel_vals(f);
        f->clr = pixel_clr(f->itr);
        mlx_put_pixel(f->bomma, hi, vi, f->clr);
      }
    }
    f->giyali = 0;
  }
}

/** Function name: giyi_julia
 * description: This function is responsible for drawing the Julia fractal.
 *
 * @param param: a pointer to the fractal struct
 *
 * @return: void
 *
 * @functions: julia_on, pixelate
 *
 * julia_on: function calculates no of iterations for a given complex number
 * pixelate: function returns a color value for a given iteration
 *
 */

void giyi_julia(void *param) {
  double hi;
  double vi;
  t_fractal *f;

  f = (t_fractal *)param;
  if (f->giyali == 1) {
    vi = 0.0;
    while (++vi < f->bomma->height) {
      hi = 0.0;
      while (++hi < f->bomma->width) {
        f->re = f->xmin + hi / f->bomma->width * (f->xmax - f->xmin);
        f->im = f->ymin + vi / f->bomma->height * (f->ymax - f->ymin);
        f->itr = julia_on(f->re, f->im, f->cre, f->cim);
        f->clr = pixel_clr(f->itr);
        mlx_put_pixel(f->bomma, hi, vi, f->clr);
      }
    }
    f->giyali = 0;
  }
}
