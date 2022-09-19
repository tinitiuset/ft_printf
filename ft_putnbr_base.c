/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:37:41 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/19 16:18:38 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long int nbr, char *base, unsigned int size)
{
	int	digits;

	digits = 1;
	if (nbr >= size)
		digits = digits + ft_putnbr_base(nbr / size, base, size);
	write (1, &base[nbr % size], 1);
	return (digits);
}
