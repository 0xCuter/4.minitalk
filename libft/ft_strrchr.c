/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:51:02 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 15:11:36 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i++;
	while (i)
	{
		if (str[i - 1] == (unsigned char)c)
			return ((char *)&str[i - 1]);
		i--;
	}
	return (NULL);
}
