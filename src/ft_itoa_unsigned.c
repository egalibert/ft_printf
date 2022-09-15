/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:15:05 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/15 12:42:29 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_uns_base(char *str, unsigned long long int num, int len, \
unsigned int base, t_flags *flags)
{
	char	*num_alph;
	int		i;

	i = 0;
	if (flags->type == 'X')
		num_alph = "0123456789ABCDEF";
	else
		num_alph = "0123456789abcdef";
	while (num >= base)
	{
		i = num % base;
		str[len--] = num_alph[i];
		num = num / base;
	}
	i = num % base;
	str[len] = num_alph[i];
	return (str);
}

int	ft_len_uns(unsigned long long int n, unsigned int base)
{
	int	len;

	len = 1;
	while (n / base > 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char	*ft_itoa_uns(unsigned long long int num, unsigned int base, \
t_flags *flags)
{
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_len_uns(num, base);
	str = ft_strnew(len);
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	str = ft_uns_base(str, num, len, base, flags);
	return (str);
}
