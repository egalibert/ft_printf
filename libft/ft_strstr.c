/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:44:48 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/03 14:43:22 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char*)s1;
	i = 0;
	if (str && s2)
	{
		if (!*s2)
			return (str);
		while (str[i])
		{
			j = 0;
			while (s2[j] == str[i + j])
			{
				if (!(s2[j + 1]))
					return (str + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
