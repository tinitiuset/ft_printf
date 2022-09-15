/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:37:41 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/15 13:58:16 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_recursive(int nbr, char *base, int size, int digits)
{
	unsigned char	i;
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		digits++;
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)size)
		ft_putnbr_base_recursive(n / size, base, size, digits);
	i = base[n % size];
	write (1, &i, 1);
	digits++;
	return (digits);
}

static int	ft_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base [i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_base(base) == 1)
	{
		while (base[i] != '\0')
			i++;
		return (ft_putnbr_base_recursive(nbr, base, i, 0));
	}
	return (1);
}
