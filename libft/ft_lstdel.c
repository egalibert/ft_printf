/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:59:35 by elliotgalib       #+#    #+#             */
/*   Updated: 2021/12/03 14:48:43 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recurse_me(t_list **alst, void (*del)(void *))
{
	if ((*alst)->next)
		recurse_me(&((*alst)->next), del);
	lstdelone(alst, del);
}

void	lstdel(t_list **alst, void (*del)(void *))
{
	if (*alst == NULL)
		return ;
	recurse_me(alst, del);
}
