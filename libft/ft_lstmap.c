/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 00:31:58 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/19 17:07:04 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	new = NULL;
	temp = NULL;
	if (lst && f)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		new = f(lst);
		temp = new;
		while (lst->next)
		{
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
		lst = NULL;
	}
	return (temp);
}
