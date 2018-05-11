/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:16:02 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:16:04 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	new = f(lst);
	first = new;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (first);
}
