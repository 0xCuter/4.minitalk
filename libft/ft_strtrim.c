/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:08:35 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 15:11:45 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;

	while (is_separator(*s1, set))
		s1++;
	len = 0;
	while (s1[len])
		len++;
	if (len == 0)
		return (malloc(0));
	while (is_separator(s1[len - 1], set))
		len--;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	s2[len] = 0;
	while (len)
	{
		s2[len - 1] = s1[len - 1];
		len--;
	}
	return (s2);
}
