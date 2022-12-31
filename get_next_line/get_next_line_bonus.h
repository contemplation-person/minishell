/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:28:22 by gyim              #+#    #+#             */
/*   Updated: 2022/12/31 12:32:59 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define OPEN_MAX 10240
# define BUFFER_SIZE  100

# include <unistd.h>
# include <stdlib.h>

typedef struct linkedlist
{
	char				str[BUFFER_SIZE + 1];
	struct linkedlist	*next;
	int					size;
}	t_buf_list;

char		*get_next_line(int fd);
t_buf_list	*lst_addback(t_buf_list **lst, char *str);
char		*print_line(t_buf_list **lst);
void		del_node(t_buf_list **lst);
t_buf_list	*lst_clear(t_buf_list **lst);

int			ft_gnl_strchr(char *str, char c);
void		strccpy(char *dst, char *src, char c);
char		*get_line(t_buf_list **lst, int len);
void		push_backup(t_buf_list **lst, t_buf_list *node);
t_buf_list	*cut_line(char	*dst, t_buf_list *curr, int *len);

#endif