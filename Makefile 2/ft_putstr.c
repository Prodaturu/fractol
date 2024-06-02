/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:45:30 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/03 05:14:53 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void ft_putstr(char *s) {
  if (s != NULL) {
    while (*s) {
      write(1, s, 1);
      s++;
    }
  }
}

void ft_putstr_fd(char *s, int fd) {
  if (s != NULL) {
    while (*s) {
      write(fd, s, 1);
      s++;
    }
  }
}
