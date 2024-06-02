/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_me_burn_ships.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:56:30 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/19 13:20:42 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void mandel_is_hooked(void *mlx, t_fractal *f) {
  f->xmin = -2.0;
  f->xmax = 1.0;
  f->ymin = -1.5;
  f->ymax = 1.5;
  mlx_loop_hook(mlx, giyi_mandel, f);
}

void burn_the_ship(void *mlx, t_fractal *f) {
  printf("The ships Burning\n");
  f->xmin = -2.0;
  f->xmax = 2.0;
  f->ymin = -2.0;
  f->ymax = 2.0;
  mlx_loop_hook(mlx, giyi_burning_ship, f);
}

void burning_ship_vals(t_fractal *f) {
  double temp;
  double zimtemp;

  temp = f->zre * f->zre - f->zim * f->zim + f->cre;
  zimtemp = f->zre * f->zim;
  if (zimtemp < 0)
    zimtemp = -zimtemp;
  f->zim = 2 * zimtemp + f->cim;
  if (temp < 0)
    temp = -temp;
  f->zre = temp;
  f->itr++;
}

void burning_ship_on(t_fractal *f, double hi, double vi) {
  f->cre = f->xmin + hi / f->bomma->width * (f->xmax - f->xmin);
  f->cim = f->ymin + vi / f->bomma->height * (f->ymax - f->ymin);
  f->re = f->cre;
  f->im = f->cim;
  f->itr = 0;
  f->zre = 0.0;
  f->zim = 0.0;
}

void giyi_burning_ship(void *param) {
  double hi;
  double vi;
  t_fractal *f;

  f = (t_fractal *)param;
  vi = 0.0;
  if (f->giyali == 1) {
    while (++vi < f->bomma->height) {
      hi = 0.0;
      while (++hi < f->bomma->width) {
        burning_ship_on(f, hi, vi);
        while (f->itr < MI && (f->zre * f->zre + f->zim * f->zim) <= 4)
          burning_ship_vals(f);
        f->clr = pixel_clr(f->itr);
        mlx_put_pixel(f->bomma, hi, vi, f->clr);
      }
    }
    f->giyali = 0;
  }
}
// f->clr = (0x000000 - 0xFFFFFF) * f->itr / MI + 0xFFFFFF;
