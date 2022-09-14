/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:24:20 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/14 14:05:32 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*hex_hash(t_flags *flags, char *str, unsigned long long num, int len2)
{
	
	if (flags->width > len2 + 2 && flags->dot == -1 && flags->zero == 1 && flags->minus == 0 && num > 0 && flags->hash == 1)
	{
		str[0] = '0';
		str[1] = 'x';
		flags->hash = 0;		
	}
	if (flags->hash == 1 && flags->dot == -1 && num > 0)
	{
		if (ft_strlen(str) - len2 >= 2 && flags->minus == 0)
		{
			str[0] = '0';
			str[1] = 'x';	
		}
		else
			str = ft_strjoin_f2("0x", str);
	}
	return (str);
}

char	*ft_manage_hex_wid(t_flags *flags, char *str, unsigned long long int num)
{
	int len;
	char *temp_str;
	int a;
	
	a = 0;
	len = flags->width - ft_strlen(str);
	if (flags->zero == 0 && flags->dot == -1 && flags->hash == 1 && num > 0)
		len -= 2;
	temp_str = ft_strnew(len);
	while (len--)
	{
		if (flags->zero == 1 && flags->dot == -1 && flags->minus == 0)
			temp_str[a++] = '0';
		else
			temp_str[a++] = ' ';
	}
	str = ft_add_hash(flags, str, num);
	if (flags->minus == 1)
		str = ft_strjoin_f1(str, temp_str);
	else
		str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char	*ft_manage_hex_pre(t_flags *flags, char *str)
{
	int i;
	int a;
	char *temp_str;
	
	a = 0;
	i = flags->dot - ft_strlen(str);
	temp_str = ft_strnew(i);
	while (i--)
		temp_str[a++] = '0';
	str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char *ft_manage_hex_str(t_flags *flags, char *str, unsigned long long int num)
{
	int len;
	int len2;
	
	len2 = ft_strlen(str);
	len = ft_strlen(str);
	if (flags->dot > len)
		str = ft_manage_hex_pre(flags, str);
	if (num == 0 && flags->dot == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (flags->hash == 1 && num > 0 && flags->dot != -1)
	{
		if (flags->type == 'x')
			str = ft_strjoin_f2("0x", str);	
		else
			str = ft_strjoin_f2("0X", str);
		flags->hash = 0;
	}
	len = ft_strlen(str);
	if (flags->width >= len)
		str = ft_manage_hex_wid(flags, str, num);
	str = hex_hash(flags, str, num, len2);
	return (str);
}

int		ft_treat_hex(va_list *args, t_flags *flags)
{
	char						*str;
	unsigned long long int	  number;
	int		  			char_count;				
	
	char_count = 0;
	if (flags->minus == 1)
		flags->zero = 0;
	number = ft_manage_u_mods(args, flags);
	str = ft_itoa_uns(number, 16, flags);
	str = ft_manage_hex_str(flags, str, number);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}











/*
#include "../includes/ft_printf.h"

static int		ft_in_put_part_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstrprec(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		ft_put_part_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_hexa(hexa, flags);
	return (char_count);
}

int				ft_treat_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_put_part_hexa(hexa, flags);
	free(hexa);
	return (char_count);
}
*/
/*
	if (num == 0 && flags->dot == 0 && flags->hash == 1)
	{
		free(str);
		str = ft_strdup("0X");
	}
	if (num == 0 && flags->dot == 1 && flags->hash == 1)
	{
		free(str);
		str = ft_strdup("0X");
*/