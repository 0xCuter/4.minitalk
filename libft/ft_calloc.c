/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:53:37 by scuter            #+#    #+#             */
/*   Updated: 2021/01/27 11:34:56 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	len;

	len = size * count;
	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
	while (len)
	{
		((unsigned char *)mem)[len - 1] = 0;
		len--;
	}
	return (mem);
}
