/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:01 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/15 13:13:30 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_me(t_list *lst, \
					t_list *(*f)(t_list *elem), t_list **new)
{
	if (lst)
	{
		*new = f(lst);
		recurse_me(lst->next, f, &((*new)->next));
	}
	else
		*new = NULL;
}

t_list	*lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	recurse_me(lst, f, &new);
	return (new);
}
