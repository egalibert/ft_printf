/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:26:03 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/19 22:49:33 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*ft_manage_f_str(t_flags *flags, char *str, long double number)
{
	char	*temp;

	temp = NULL;
	if (number < 0)
	{
		temp = ft_strjoin_f2("-",str);
		free(str);
		str = temp;
	}
	else if (number >= 0 && (flags->plus == 1 || flags->space == 1))
	{
		if (flags->plus == 1)
			temp = ft_strjoin_f2("+",str);
		else if (flags->space == 1)
			temp = ft_strjoin_f2(" ", str);
		free(str);
		str = temp;
	}
	return (str);
}

char	*ft_add_float_part(long double f_num, char *str, int precision)
{
	long double	num;
	int	i;

	num = f_num - (long long)f_num;
	str = ft_strnew(precision + 1);
	if (!str)
		return (0);
	i = 1;
	str[0] = '.';
	while (precision-- > 0)
	{
		num *= 10.0;
		str[i++] = (long long)num + '0';
		num = num - (long long)num;
	}
	return (str);
}

char	*ft_ftoa(long double num, char *str, int precision)
{
	char			*float_part;

	float_part = NULL;
	str = ft_itoa_signed((long long)num);
	if (precision != 0)
		float_part = ft_add_float_part(num, float_part, precision);
	else
		float_part = ft_strdup("");
	str = ft_strjoin_f1(str, float_part);
	free(float_part);
	
	/*if (1.0 - remainder < 0 + remainder
		|| (1.0 - remainder == 0 + remainder
			&& ((str)[ft_strlen((str)) - 1] + 1 - '0') % 2 == 0))
		round_up(str, ft_strlen(str) - 1);*/
	return (str);
}

long double	ft_manage_f_mods(va_list *args, t_flags *flags)
{
	if (flags->mods == 5)
		return ((long double)va_arg(*args, long double));
	else
		return ((double)va_arg(*args, double));

}

long double	ft_rounder(long double num, t_flags *flags)
{
	long double	temp;

	temp = num;
	if (num < 0)
		num *= -1;
	temp = num * ft_power(flags->dot, 10);
	if (temp - (long long)temp == 0.5)
	{
		// if number is 0
		if ((long long)temp % 2 == 0)
			num = temp / ft_power(flags->dot, 10);
		else
			// temp = temp + 0.5
			num = (temp + 0.5) / ft_power(flags->dot, 10);
	}
	else
		num = (temp + 0.5) / ft_power(flags->dot, 10);
	//printf("value of num is |%Lf|\n", num);
	return (num);
}

int	ft_treat_float(va_list *args, t_flags *flags)
{
	char					*str;
	long double				number;
	int						char_count;

	str = NULL;
	char_count = 0;
	number = ft_manage_f_mods(args, flags);
	if (flags->dot == -1)
		flags->dot = 6;
	number = ft_rounder(number, flags);
	str = ft_ftoa(number, str, flags->dot);
	//str = ft_manage_f_str(flags, str, number);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}