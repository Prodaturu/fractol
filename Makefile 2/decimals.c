/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:35:17 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/19 13:55:10 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int pixel_clr(int itr) {
  int red;
  int green;
  int blue;

  red = itr % 128;
  green = itr % 64;
  blue = itr % 255;
  return (red << 24 | green << 15 | blue << 22 | 255);
}

double decimalpart(char **num_str) {
  double decimal;
  int power;

  decimal = 0.0;
  power = 1;
  while (**num_str >= '0' && **num_str <= '9') {
    power += 1;
    decimal = decimal * 10.0 + (double)(**num_str - '0');
    (*num_str)++;
  }
  while (power > 1) {
    decimal /= 10.0;
    power--;
  }
  return (decimal);
}

double realpart(char **num_str) {
  double real;

  real = 0.0;
  while (**num_str >= '0' && **num_str <= '9') {
    real = real * 10.0 + (double)(**num_str - '0');
    (*num_str)++;
  }
  return (real);
}

double ft_atof(char *num_str) {
  double result;
  int sign;

  result = 0.0;
  sign = 1.0;
  while (*num_str == 32 || (*num_str >= 9 && *num_str <= 13))
    num_str++;
  if (*num_str == '-' || *num_str == '+') {
    if (*num_str == '-')
      sign = -1.0;
    num_str++;
  }
  result = realpart(&num_str);
  if (*num_str == '.') {
    num_str++;
    result += decimalpart(&num_str);
  }
  return (result *= sign, result);
}
