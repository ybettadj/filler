/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:15:32 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:15:33 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nextlist;

	lst = *alst;
	while (lst)
	{
		del((lst)->content, (lst)->content_size);
		free(lst);
		nextlist = lst->next;
		lst = nextlist;
	}
	*alst = NULL;
}
