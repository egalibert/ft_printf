/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:21:58 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/02 01:21:59 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_flags(t_flags *flags)
{

	flags->dot = -1;
	flags->minus = 0;
	flags->type= 0;
	flags->width = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->mods = 0;
	flags->over = 0;
	flags->min_over = 0;
}

int			ft_treat_save(const char *save, va_list *args, t_flags *flags)
{
	int			i;
	int			char_count;
	char		*str;
	int			x;

	x = 0;
	i = 1;
	str = ft_strnew(100);
	char_count = 0;
	ft_init_flags(flags);
	while (save[i] && !ft_is_in_type_list(save[i]))
	{
		if (ft_is_in_flags_list(save[i]))
			str[x++] = save[i];
		i++;	
	}
	if (ft_strcmp(str, "") != 0)
		ft_flag_parse(str, flags);
	else
		free(str);
	flags->type = save[i];
	char_count = ft_treatment(args, flags);
	return (char_count);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			char_count;
	int 		i;
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	i = -1;
	char_count = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (ft_is_in_type_list(format[i + 1]) || ft_is_in_flags_list(format[i + 1]))
				char_count += ft_treat_save(&format[i++], &args, flags);
			while (ft_is_in_flags_list(format[i]))
				i++;
		}
		else
			char_count += ft_putchar2(format[i]);
	}
	free(flags);
	va_end(args);
	return (char_count);
}

/*int			ft_printf(const char *format, ...)
{
	const char	*save;
	va_list		args;
	int			char_count;

	save = ft_strdup(format);
	char_count = 0;
	va_start(args, format);
	char_count += ft_treat_save(save, &args);
	va_end(args);
	free((char *)save);
	return (char_count);
}
*/ 

/* 
int			ft_treat_save(const char *save, va_list *args)
{
	int			i;
	t_flags		*flags;
	int			char_count;

	i = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	char_count = 0;
	while (1)
	{
		ft_init_flags(flags);
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = ft_flag_parse(save, ++i, flags, args);
			if (ft_is_in_type_list(save[i]))
				char_count += ft_treatment((char)flags->type, flags, args);
			else if (save[i])
				char_count += ft_putchar2(save[i]);
		}
		else if (save[i] != '%')
			char_count += ft_putchar2(save[i]);
		i++;
	}
	return (char_count);
	*/ 