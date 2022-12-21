/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/21 14:18:55 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_LIST_H
# define BUILTIN_LIST_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/errno.h>

//extern int	error_code;

typedef enum e_bool
{
	FALSE,
	TRUE,
}t_bool;

typedef struct s_env_node
{
	char				*key;
	char				*value;
}t_env_node;

t_env_node	*new_env_node(char *key, char *value);
void		env_del(t_env_node *target);
#endif