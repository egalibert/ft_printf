/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotgalibert <elliotgalibert@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:47:34 by elliotgalib       #+#    #+#             */
/*   Updated: 2021/12/03 14:50:34 by elliotgalib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	f(lst);
	lstiter(lst->next, f);
}
