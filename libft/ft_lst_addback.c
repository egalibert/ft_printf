/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:13:48 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/15 13:01:19 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_addback(t_list *head, t_list *new)
{
	t_list	*temp;

	if (!head || !new)
		return ;
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
