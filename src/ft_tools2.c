/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:09:39 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/14 14:09:33 by elliotgalib      ###   ########.fr       */
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

/*
int		ft_base_numlen(long long int num, int base)
{
	int	len;

	len = 0;
	if (num < 0 || num == 0)
		len ++;
	while (num)
	{
		num = num / base;
		len++;
	}
	return(len);
}

char	*ft_itoa_base(long long int num, int base)
{
	char 	*str;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	i = ft_base_numlen(num, base);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = ft_base(num, base);
		num = num / base;
		i--;
	}
}	
*/