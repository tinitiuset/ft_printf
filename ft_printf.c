/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:18:28 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/13 14:08:01 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_text(char const *s, void *arg)
{
	char			*sarg;
	unsigned int	i;

	if (*s == 'c')
		return (write(1, &arg, 1));
	i = -1;
	sarg = (char *)arg;
	while (sarg[++i])
		write (1, &sarg[i], 1);
	return (i + 1);
}

int	ft_convert_dec(char const *s, int arg)
{
	if (*s == 'u')
		return (ft_putnbr((unsigned int)arg, 1));
	return (ft_putnbr(arg, 1));
}

int	ft_convert_hexa(char const *s)
{
	return (0);
}

int	ft_convert_filter(char const *s, va_list args)
{
	s++;
	if (*s == 'c' || *s == 's')
		return (ft_convert_text(s, va_arg(args, char *)));
	if (*s == 'd' || *s == 'i' || *s == 'u')
		return (ft_convert_dec(s, va_arg(args, int)));
	if (*s == 'p' || *s == 'x' || *s == 'X')
		return (ft_convert_hexa(s));
	if (*s == '%')
	{
		write (1, "%", 1);
		return (2);
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
		}
		else
		{
			s = (s + ft_convert_filter(s, args));
		}	
		s++;
	}
	va_end(args);
	return (0);
}
