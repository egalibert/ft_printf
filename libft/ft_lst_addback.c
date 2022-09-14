/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:13:48 by elliotgalib       #+#    #+#             */
/*   Updated: 2021/12/16 15:13:49 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_addback(t_list *head, t_list *new)
{
	t_list	*temp;

	if (!head || !new)
		return ;
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}