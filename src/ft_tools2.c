/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:09:39 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/19 21:40:38 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_hash(t_flags *flags, char *str, unsigned long long num)
{
	if (flags->zero == 0 && flags->dot == -1 && flags->hash == 1 && num > 0)
	{
		if (flags->type == 'x')
			str = ft_strjoin_f2("0x", str);
		else
			str = ft_strjoin_f2("0X", str);
		flags->hash = 0;
	}
	return (str);
}

int	ft_power(int power, int base)
{
	int	i;
	int number;

	number = 1;
	i = 0;
	while (i < power)
	{
		number *= base;
		i++;
	}
	return (number);
}