/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:39 by resulbozdem       #+#    #+#             */
/*   Updated: 2023/01/18 17:40:40 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(unsigned int nbr, int *i, char *base)
{
	if (nbr < 16)
	{
		if (nbr < 10)
			*i += ft_putchar_fd2(nbr + '0', 1);
		else
			*i += ft_putchar_fd2(base[nbr % 16], 1);
	}
	if (nbr >= 16)
	{
		ft_x(nbr / 16, i, base);
		ft_x(nbr % 16, i, base);
	}
	return (*i);
}
