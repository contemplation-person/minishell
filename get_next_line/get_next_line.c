/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:27:51 by gyim              #+#    #+#             */
/*   Updated: 2022/07/26 10:20:28 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*lst_addback(t_list **lst, char *str)
{
	t_list	*curr;
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	strccpy(newnode->str, str, '\0');
	newnode->size = ft_strchr(str, '\0');
	newnode->next = NULL;
	if (!(*lst))
	{
		*lst = newnode;
		return (newnode);
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = newnode;
	return (newnode);
}

char	*print_line(t_list **lst)
{
	t_list	*curr;
	char	*ret;
	int		ret_len;

	if (!*lst)
		return (NULL);
	curr = *lst;
	ret_len = 0;
	while (curr != NULL && ft_strchr(curr->str, '\n') == -1)
	{
		ret_len += curr->size;
		curr = curr->next;
	}
	if (curr != NULL && ft_strchr(curr->str, '\n') != -1)
		ret_len += (ft_strchr(curr->str, '\n') + 1);
	ret = get_line(lst, ret_len);
	return (ret);
}

void	del_node(t_list **lst)
{
	(*lst)->size = -1;
	free(*lst);
	lst = NULL;
}

t_list	*lst_clear(t_list **lst)
{
	t_list	*curr;
	t_list	*temp;

	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		del_node(&curr);
		curr = temp;
	}
	*lst = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*head[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_len;
	t_list			*newnode;

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return ((char *)lst_clear(&head[fd]));
	if (head[fd] != NULL && ft_strchr(head[fd]->str, '\n') != -1)
		return (print_line(&head[fd]));
	while (1)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buf[read_len] = '\0';
		newnode = lst_addback(&head[fd], buf);
		if (!newnode)
			return ((char *)lst_clear(&head[fd]));
		if (ft_strchr(buf, '\n') != -1)
			break ;
	}
	return (print_line(&head[fd]));
}
