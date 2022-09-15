/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:00:51 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/15 13:01:04 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstdelone(t_list **alst, void (*del)(void*))
{
	del((*alst)->content);
	free(*alst);
	*alst = NULL;
}
