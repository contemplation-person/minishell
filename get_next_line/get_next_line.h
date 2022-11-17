/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:28:22 by gyim              #+#    #+#             */
/*   Updated: 2022/07/26 10:15:32 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 10240

typedef struct linkedlist
{
	char				str[BUFFER_SIZE + 1];
	struct linkedlist	*next;
	int					size;
}	t_list;

char	*get_next_line(int fd);
t_list	*lst_addback(t_list **lst, char *str);
char	*print_line(t_list **lst);
void	del_node(t_list **lst);
t_list	*lst_clear(t_list **lst);

int		ft_strchr(char *str, char c);
void	strccpy(char *dst, char *src, char c);
char	*get_line(t_list **lst, int len);
void	push_backup(t_list **lst, t_list *node);
t_list	*cut_line(char	*dst, t_list *curr, int *len);

#endif