/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:27:16 by egaliber          #+#    #+#             */
/*   Updated: 2021/11/04 15:53:03 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*res;
	unsigned int	len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	res = (char *)malloc(sizeof(*res) * (len + 1));
	len = 0;
	while (s1[len] != '\0')
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
