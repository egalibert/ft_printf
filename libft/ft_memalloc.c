/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:46:55 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/15 13:00:10 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;
	char	*p;

	tmp = (char *)malloc(size);
	if (tmp == NULL)
		return (NULL);
	p = tmp;
	while (size--)
		*p++ = 0;
	return (tmp);
}
