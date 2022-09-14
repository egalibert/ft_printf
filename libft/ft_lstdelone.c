/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:00:51 by elliotgalib       #+#    #+#             */
/*   Updated: 2021/12/03 14:48:58 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstdelone(t_list **alst, void (*del)(void*))
{
	del((*alst)->content);
	free(*alst);
	*alst = NULL;
}