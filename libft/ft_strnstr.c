/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:42:13 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/03 14:46:20 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (needle == NULL)
		return ((char *) haystack);
	while (haystack[a] != '\0' && a < n)
	{
		b = 0;
		while (needle[a + b] == haystack[b] && needle[b] != 0 && a + b < n)
		{
			if (needle[b + 1] == '\0')
				return ((char *)(haystack + a));
			b++;
		}
		a++;
	}
	return (NULL);
}
