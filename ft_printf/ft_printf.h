/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:22 by resulbozdem       #+#    #+#             */
/*   Updated: 2023/01/18 17:37:02 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar_fd2(char c, int fd);
int	ft_putstr_fd2(char *s, int fd);
int	ft_putnbr_fd2(int n, int fd);
int	ft_putunint(unsigned int number);
int	ft_pointer(unsigned long ptr);
int	ft_x(unsigned int nbr, int *i, char *base);

#endif
