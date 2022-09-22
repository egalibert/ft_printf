/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:08:44 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/22 13:03:02 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

long double	ft_rounding(int i, long double num)
{
	long double	round;
	long double	r;

	r = 0.5;
	while (i > 0)
	{
		r = r / 10.0;
		i--;
	}
	round = num + r;
	return (round);
}

void	ft_star(va_list *args, t_flags *flags)
	{
	if (flags->star == 1 && flags->dot == -1)
		flags->width = va_arg(*args, long long);
	if (flags->star == 1 && flags->dot == 0)
		flags->dot = va_arg(*args, long long);
	if (flags->star == 2)
	{
		flags->width = va_arg(*args, long long);
		flags->dot = va_arg(*args, long long);
	}
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
}

char	*ft_add_minus(char *str, t_flags *flags, int is_neg)
{
	if (is_neg == 1 && flags->zero == 0)
	{
		str = ft_strjoin_f2("-", str);
		flags->min_over = 1;
	}
	return (str);
}