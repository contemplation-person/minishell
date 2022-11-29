/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:32 by gyim              #+#    #+#             */
/*   Updated: 2022/11/29 18:30:40 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_INPUT_H
# define SPLIT_INPUT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef enum e_check_list
{
	BRACKET = 1,
	SQUARE_BRACKET,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	BACKTICK,
}	t_check_list;

typedef struct s_tnode
{
	char			*token;
	struct s_tnode	*next;
}	t_tnode;

typedef struct s_tlist_info
{
	t_tnode	*head;
	int		cnt;
}	t_tlist_info;

// token_list.c
t_tlist_info	*tlist_init(void);
t_tnode			*make_node(char *str);
t_tnode			*lst_last(t_tlist_info *list_info);
void			list_add(t_tlist_info *list, char *str);

// split_input.c
t_tlist_info	*split_input(char *input);
int				is_space(char ch);
int				is_quote(char ch);
int				is_brace(char input);
int				is_op(char *str);
void			add_substr(t_tlist_info *list, char *str, int start, int end);
#endif

// gcc -lreadline -L../readline -I../readline $(your *.c file)

