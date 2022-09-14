/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:49:43 by elliotgalib       #+#    #+#             */
/*   Updated: 2021/11/30 14:51:56 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lstnew(void *content)
{
	t_list	*link;

	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	link->content = (void*)content;
	link->next = NULL;
	return (link);
}