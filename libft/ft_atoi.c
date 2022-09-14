/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:12:13 by egaliber          #+#    #+#             */
/*   Updated: 2022/08/23 14:16:04 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_atoi(const char *str)
{
    int    c;
    int    s;
    int    res;

    c = 0;
    s = 1;
    res = 0;
    while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
    	|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
        c++;
    if (str[c] == '-' || str[c] == '+')
    {
        if (str[c] == '-')
            s = -1;
        c++;
    }
    while (str[c] >= '0' && str[c] <= '9')
    {
        res = (res * 10) + (str[c] - '0');
        c++;
    }
    return (res * s);
}
