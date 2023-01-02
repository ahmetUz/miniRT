/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:59:37 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/09 10:41:33 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive_putnbr(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd('0' + nb, fd);
	else
	{
		ft_recursive_putnbr((int)(nb / 10), fd);
		ft_putchar_fd('0' + (nb % 10), fd);
	}
}
