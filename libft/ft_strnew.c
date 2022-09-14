/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:55:31 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/08 20:34:41 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;
	t = (char *)malloc(sizeof(*t) * (size + 1));
	if (!t)
		return (NULL);
	ft_memset(t, '\0', size + 1);
	return (t);
}
