/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:53:00 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/19 14:17:51 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_digits(long n)
{
	int	i;

	i = 0;
	if (0 > n || !n)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_long_itoa(long n)
{
	char	*s;
	long	digits;
	long	i;

	digits = ft_digits(n);
	s = malloc(digits + 1);
	if (!s)
		return (0);
	s[digits] = '\0';
	i = 0;
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
		i++;
	}
	while (digits-- > i)
	{
		s[digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
