/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:18:28 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/13 11:47:45 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_text(char const *s)
{
	return (0);
}

int	convert_dec(char const *s)
{
	return (0);
}

int	convert_hexa(char const *s)
{
	return (0);
}

int	convert_filter(char const *s)
{
	s++;
	if (*s == 'c' || *s == 's')
		return (convert_text(s));
	if (*s == 'd' || *s == 'i' || *s == 'u')
		return (convert_dec(s));
	if (*s == 'p' || *s == 'x' || *s == 'X')
		return (convert_hexa(s));
	if (*s == '%')
	{
		write (1, "%", 1);
		return (2);
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
		}
		else
		{
			s = (s + convert_filter(s));
		}	
		s++;
	}
	return (0);
}
