/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:00:14 by mvalient          #+#    #+#             */
/*   Updated: 2022/09/19 16:16:36 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(char const *s, ...);
int		ft_putnbr_base(unsigned long int nbr, char *base, unsigned int size);
char	*ft_long_itoa(long n);

#endif
