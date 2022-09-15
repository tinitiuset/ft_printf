/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:37:41 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/15 17:53:18 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_recursive(unsigned long int nbr, char *base, int size,
	int digits)
{
	unsigned char	i;

	if (nbr >= size)
		ft_putnbr_base_recursive(nbr / size, base, size, digits);
	i = base[nbr % size];
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

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_base(base) == 1)
	{
		while (base[i] != '\0')
			i++;
		return (ft_putnbr_base_recursive(nbr, base, i, 0));
	}
	return (0);
}
