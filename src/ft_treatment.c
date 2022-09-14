/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:41:53 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/13 13:04:06 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_check_mods(int c)
{
    if (c == 'h' || c == 'l' || c == 'L')
        return (1);
    else
        return (0);
}

int		ft_is_in_type_list(int c)
{
	if  (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
        || c == 'u'|| c == 'x' || c == 'X' || c == '%' || c == 'f'
        || c == 'o')
        return (1);
    else
        return (0);
}

int		ft_is_in_flags_list(int c)
{
    if  (c == '#' || c == '-' || c == '+' || c == '.' || c == ' '
        || ft_isdigit(c) || ft_check_mods(c))
        return (1);
    else
        return (0);
}


int        ft_treatment(va_list *args, t_flags *flags)
{
    if (flags->type == 'c')
        return (ft_treat_char(args, flags));
    if (flags->type == 's')
        return (ft_treat_string(args, flags));
    if (flags->type == 'i' || flags->type == 'd')
        return (ft_treat_int(args, flags));
    if (flags->type == 'u')
        return (ft_treat_uns_int(args, flags));
    if (flags->type == 'o')
        return (ft_treat_oct(args, flags));
    if (flags->type == 'x' || flags->type == 'X')
        return (ft_treat_hex(args, flags));
    if (flags->type == 'p')
        return (ft_treat_pointer(args, flags));
    if (flags->type == '%')
        return (ft_treat_percent(flags));

    

    
    return (0);
}

