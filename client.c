/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:16 by scuter            #+#    #+#             */
/*   Updated: 2021/10/13 19:14:59 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	errors(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = 0;
	while (argv[1][i])
	{
		if (!strchr("0123456789", argv[1][i]))
			return (1);
		i++;
	}
	return (0);
}

static void	send_len(int len, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len /= 2;
		usleep(WAIT_TIME);
		i++;
	}
}

static void	send_char(unsigned char chr, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (chr % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		chr /= 2;
		usleep(WAIT_TIME);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;
	int	i;

	if (errors(argc, argv))
		return (1);
	pid = ft_atoi(argv[1]);
	if (!pid)
		return (1);
	len = ft_strlen(argv[2]);
	send_len(len, pid);
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char(0, pid);
}
