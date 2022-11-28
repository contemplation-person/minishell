/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:28:22 by gyim              #+#    #+#             */
/*   Updated: 2022/11/28 16:01:20 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define OPEN_MAX 10240
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdlib.h>

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