/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:53:52 by spetit            #+#    #+#             */
/*   Updated: 2014/11/05 19:35:18 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int i;

	i = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = (nb * -1);
	}
	while (nb / i >= 10)
	{
		i = i * 10;
	}
	while (i > 0)
	{
		ft_putchar(((nb / i) % 10) + 48);
		i = i / 10;
	}
}
