/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:18:28 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/15 17:54:16 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_text(char const *s, void *arg)
{
	if (*s == 'c')
		return (write(1, &arg, 1));
	return (write(1, arg, ft_strlen((char *)arg)));
}

static int	ft_convert_dec(char const *s, int arg)
{
	if (*s == 'u')
		if (arg < 0)
			return (ft_convert_text(s, ft_itoa((4294967296 + arg) / 100000))
				+ ft_convert_text(s, ft_itoa((4294967296 + arg) % 100000)));
	return (ft_convert_text(s, ft_itoa(arg)));
}

static int	ft_convert_hexa(char const *s, unsigned long int arg)
{
	if (*s == 'x')
		return (ft_putnbr_base((unsigned int)arg, "0123456789abcdef"));
	if (*s == 'X')
		return (ft_putnbr_base((unsigned int)arg, "0123456789ABCDEF"));
	return (ft_convert_text("s", "0x")
		+ ft_putnbr_base(arg, "0123456789abcdef"));
}

int	ft_convert_filter(char const *s, va_list args)
{
	s++;
	if (*s == 'c' || *s == 's')
		return (ft_convert_text(s, va_arg(args, char *)));
	if (*s == 'd' || *s == 'i' || *s == 'u')
		return (ft_convert_dec(s, va_arg(args, int)));
	if (*s == 'p' || *s == 'x' || *s == 'X')
		return (ft_convert_hexa(s, va_arg(args, unsigned long int)));
	if (*s == '%')
		return (write (1, "%", 1));
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
			ft_convert_filter(s, args);
			s++;
		}	
		s++;
	}
	va_end(args);
	return (0);
}
