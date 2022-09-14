/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:10:43 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/02 23:37:16 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>


int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


char		*check_width_str(t_flags *flags, char *print_str, int char_count)
{
	char *str;
	int i;
	
	if (flags->width >= char_count)
		i = (flags->width);
	str = ft_strnew(flags->width);
	if (!str)
		return (NULL);
	i = 0;
	while (flags->width-- > char_count)
	{
		if (flags->zero == 1)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;	
	}
	if (flags->minus == 1)
		print_str = ft_strjoin_f1(print_str, str);
	else
		print_str = ft_strjoin_f2(str, print_str);
	free(str);
	return (print_str);
}


char		*ft_manage_str_prec(t_flags *flags, int str_len, char *print_str)
{
	int char_count;
	char *temp_str;
	
	if (flags->dot <= str_len)
		temp_str = ft_strsub(print_str, 0, flags->dot);
	else
		temp_str = ft_strsub(print_str, 0, str_len);
		char_count = ft_strlen(temp_str);
		free(print_str);
		temp_str = check_width_str(flags, temp_str, char_count);
	
	return (temp_str);
}

int		ft_treat_string(va_list *args, t_flags *flags)
{
	int char_count;
	char *str;
	char *print_str;
	

	str = va_arg(*args, char *);
	if (!str)
		print_str = ft_strdup("(null)");
	else
		print_str = ft_strdup(str);
	char_count = ft_strlen(print_str);
	if (flags->dot != -1 || flags->width != 0 || flags->minus != 0 )
	{
		if (flags->dot != -1)
			print_str = ft_manage_str_prec(flags, char_count, print_str);
		else
			print_str = check_width_str(flags, print_str, char_count);
	}
	char_count = ft_strlen(print_str);
	ft_putstr(print_str);
	ft_strdel(&print_str);
	return (char_count);
}

/*

#include "../includes/ft_printf.h"
#include <stdio.h>


int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


int	check_width_str(t_flags *flags, char *str, int char_count)
{
	if (flags->minus == 1)
	{
		ft_putstr(str);
		if (flags->width > ft_strlen2(str))
			while (flags->width-- > ft_strlen2(str))
			{	ft_putchar(' ');
				char_count++;
			}

	}
	else
	{
		while (flags->width-- > ft_strlen2(str))
		{
			if (flags->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			char_count++;	
		}
		ft_putstr(str);	
	}
	free(str);
	return (char_count);
}


int		ft_manage_str_prec(t_flags *flags, int str_len, char *print_str)
{
	int char_count;
	char *temp_str;

	char_count = 0;
	if (flags->dot == -1)
		char_count = check_width_str(flags, print_str, char_count);
	else 
	{	
		if (flags->dot <= str_len)
			temp_str = ft_strsub(print_str, 0, flags->dot);
		else
			temp_str = ft_strsub(print_str, 0, str_len);
		free(print_str);
		char_count = check_width_str(flags, temp_str, char_count);
	}	
	return (char_count);
}

int		ft_treat_string(va_list *args, t_flags *flags)
{
	int char_count;
	char *str;
	char *print_str;
	

	str = va_arg(*args, char *);
	if (!str)
		print_str = ft_strdup("(null)");
	else
		print_str = ft_strdup(str);
	char_count = ft_strlen(print_str);
	if (flags->dot != -1 || flags->width != 0 )
		char_count = ft_manage_str_prec(flags, char_count, print_str);
	else
	{
		ft_putstr(print_str);
		ft_strdel(&print_str);
	}
	return (char_count);
}








	if (flags->minus == 0)
		while (char_count > ft_strlen2(print_str))
			{
				ft_putchar(' ');
				char_count--;
			}
*/
/*static int		ft_put_part_int(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int				ft_treat_string(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.width, flags.dot, 0);
	else
		char_count += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}
*/ 