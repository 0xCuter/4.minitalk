/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:39:20 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 15:02:47 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	else if (d > s)
	{
		s = s + n - 1;
		d = d + n - 1;
		while (n)
		{
			*d-- = *s--;
			n--;
		}
	}
	return (dest);
}
