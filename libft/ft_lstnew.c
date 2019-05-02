/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:58:42 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/18 21:48:03 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	if (content == NULL)
	{
		element->content_size = 0;
		element->content = NULL;
	}
	else
	{
		element->content_size = content_size;
		element->content = (t_list *)malloc(sizeof(t_list));
		ft_memcpy(element->content, content, content_size);
	}
	element->next = NULL;
	return (element);
}
