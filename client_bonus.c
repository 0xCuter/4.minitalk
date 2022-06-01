/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:16 by scuter            #+#    #+#             */
/*   Updated: 2021/10/13 19:24:48 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

static void	send_str(char *str, int pid)
{
	int	i;

	send_len(ft_strlen(str), pid);
	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char(0, pid);
}

static void	message(int sig)
{
	(void)sig;
	ft_putendl_fd("message delivered successfully!", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*client_pid;

	if (argc == 3)
	{
		signal(SIGUSR1, message);
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
			return (1);
		client_pid = ft_itoa(getpid());
		send_str(client_pid, server_pid);
		free(client_pid);
		send_str(argv[2], server_pid);
		sleep(1);
	}
	return (1);
}
