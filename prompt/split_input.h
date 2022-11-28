/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:32 by gyim              #+#    #+#             */
/*   Updated: 2022/11/28 20:31:04 by gyim             ###   ########seoul.kr  */
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

typedef struct s_tlist
{
	char	*token;
	t_tlist	*next;
}	t_tlist;

typedef struct s_tlist_info
{
	t_list	*head;
	int		cnt;
}	t_tlist_info;

#endif

// gcc -lreadline -L../readline -I../readline $(your *.c file)

