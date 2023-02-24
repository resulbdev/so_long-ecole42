/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:11 by resulbozdem       #+#    #+#             */
/*   Updated: 2023/01/18 17:39:58 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long ptr)
{
	int	res;

	res = 0;
	if (ptr > 15)
		res += ft_pointer(ptr / 16);
	res += ft_putchar_fd2("0123456789abcdef"[ptr % 16], 1);
	return (res);
}
