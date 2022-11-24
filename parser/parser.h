/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:10:54 by gyim              #+#    #+#             */
/*   Updated: 2022/11/24 19:32:38 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	char	**tokens;
	char	*op;
	t_node	*left_node;
	t_node	*right_node;
}	t_node;

char	**parser(char *input);
void	change_wspace(char *tmp);
void	free_line(char **words);

//tree.c
t_node	*make_tree(char **lines);
int		find_op(char **tokens);
char	**get_left_tokens(char **tokens, int op_index);
char	**get_right_tokens(char **tokens, int op_index);

#endif