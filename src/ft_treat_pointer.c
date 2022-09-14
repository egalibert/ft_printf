#include "../includes/ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:24:20 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/12 17:06:43 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*ft_manage_ptr_wid(t_flags *flags, char *str)
{
	int len;
	char *temp_str;
	int a;
	
	a = 0;
	len = flags->width - ft_strlen(str);
	temp_str = ft_strnew(len);
	while (len--)
	{
		if (flags->zero == 1 && flags->dot == -1 && flags->minus == 0)
			temp_str[a++] = '0';
		else
			temp_str[a++] = ' ';
	}
	if (flags->minus == 1)
		str = ft_strjoin_f1(str, temp_str);
	else
		str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char	*ft_manage_ptr_pre(t_flags *flags, char *str)
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

char *ft_manage_ptr_str(t_flags *flags, char *str)
{
	int len;

	len = ft_strlen(str);
	if (flags->dot > len)
		str = ft_manage_ptr_pre(flags, str);
	if (flags->dot == 0 && ft_strequ(str, "0"))
	{
		free(str);
		str = ft_strdup("");
	}
	if (flags->type == 'p')
		str = ft_strjoin_f2("0x", str);
	len = ft_strlen(str);
	if (flags->dot == -1 && flags->zero == 1 && flags->minus != 1)
		str[1] = '0';
	if (flags->width >= len)
		str = ft_manage_ptr_wid(flags, str);
	if (flags->dot == -1 && flags->zero == 1 && flags->minus != 1)
		str[1] ='x';
	return (str);
}

int		ft_treat_pointer(va_list *args, t_flags *flags)
{
	char						*str;
	void	  				*number;
	int		  			char_count;				
	
	char_count = 0;
	number = va_arg(*args, void *);
	str = ft_itoa_uns((unsigned long long)number, 16, flags);
	str = ft_manage_ptr_str(flags, str);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}















/*
static int	ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(pointer), 1);
		char_count += ft_putstrprec(pointer, flags.dot);
	}
	else
		char_count += ft_putstrprec(pointer, ft_strlen(pointer));
	return (char_count);
}

int			ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		char_count;
	
	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_treat_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}
*/