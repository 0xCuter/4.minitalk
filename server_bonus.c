/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:18 by scuter            #+#    #+#             */
/*   Updated: 2021/10/13 19:22:06 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	power(int pow)
{
	int	ret;

	ret = 1;
	while (pow > 0)
	{
		ret *= 2;
		pow--;
	}
	return (ret);
}

static void	init(int *len_flag, char **str, int *i)
{
	static int	client_pid;

	if (!client_pid)
		client_pid = ft_atoi(*str);
	else
	{
		ft_putendl_fd(*str, 1);
		kill(client_pid, SIGUSR1);
		client_pid = 0;
	}
	*len_flag = 0;
	free(*str);
	*str = NULL;
	*i = 0;
}

static void	decode_len(int *bit, char **str, int *flag, int sig)
{
	static int	len;

	len = 0;
	if (sig == SIGUSR1)
		len += power(*bit);
	if (*bit == 31)
	{
		*flag = 1;
		*str = ft_calloc(len, sizeof(char));
		if (!(*str))
			exit(1);
		*bit = 0;
		return ;
	}
	(*bit)++;
}

static void	decode(int sig)
{
	static char	*str;
	static int	len_flag;
	static int	bit;
	static int	chr;
	static int	i;

	if (!len_flag)
		decode_len(&bit, &str, &len_flag, sig);
	else
	{
		if (sig == SIGUSR1)
			chr += power(bit);
		if (bit == 7)
		{
			str[i] = chr;
			i++;
			bit = 0;
			if (chr == 0)
				return (init(&len_flag, &str, &i));
			chr = 0;
			return ;
		}
		bit++;
	}
}

int	main(void)
{
	int	pid;

	pid = (int)(getpid());
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, decode);
	signal(SIGUSR2, decode);
	while (1)
		pause();
}
