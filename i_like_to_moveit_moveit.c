/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_like_to_moveit_moveit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:41:10 by sprodatu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/16 20:09:42 by sprodatu         ###   ########.fr       */
=======
/*   Updated: 2024/05/03 01:43:40 by sprodatu         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void up_down(mlx_key_data_t key, t_fractal *f) {
  if (key.key == MLX_KEY_UP && key.action == MLX_PRESS) {
    f->ymin += (f->ymax - f->ymin) * 0.1;
    f->ymax += (f->ymax - f->ymin) * 0.1;
  }
  if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS) {
    f->ymin -= (f->ymax - f->ymin) * 0.1;
    f->ymax -= (f->ymax - f->ymin) * 0.1;
  }
}

void left_right(mlx_key_data_t key, t_fractal *f) {
  if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS) {
    f->xmin += (f->xmax - f->xmin) * 0.1;
    f->xmax += (f->xmax - f->xmin) * 0.1;
  }
  if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS) {
    f->xmin -= (f->xmax - f->xmin) * 0.1;
    f->xmax -= (f->xmax - f->xmin) * 0.1;
  }
}

void moving(mlx_key_data_t key, void *param) {
  t_fractal *f;

  f = (t_fractal *)param;
  if ((key.key == MLX_KEY_UP || key.key == MLX_KEY_DOWN) &&
      key.action == MLX_PRESS)
    up_down(key, f);
  if ((key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT) &&
      key.action == MLX_PRESS)
    left_right(key, f);
  if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
    return (exit(0));
  f->giyali = 1;
}
