/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:14:08 by scuter            #+#    #+#             */
/*   Updated: 2021/01/27 11:37:57 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;

	abs = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		abs = -n;
	}
	if (abs > 9)
		ft_putnbr_fd(abs / 10, fd);
	abs = '0' + (abs % 10);
	write(fd, &abs, 1);
}
