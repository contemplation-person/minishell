# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/16 08:13:14 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:=	minishell
CC 				:=	cc
CFLAGES 		:=	-Wall -Werror -Wextra
READLINE_LIB	:=	-lreadline -Lreadline
READLINE_INC	:=	-I./readline
SRC 			:=	parser_list/tree.c \
					parser_list/prompt.c	parser_list/utils.c			excute/excute.c	parser_list/search_tree.c	parser_list/utils2.c	parser_list/split_input.c	parser_list/valid_check.c	parser_list/token_check.c \
					prompt/prompt.c			parser_list/token_list.c	parser_list/parser.c	parser_list/token_list2.c \
					#builtin/builtin_list.c	builtin/cd.c				builtin/echo.c			builtin/env.c	builtin/exit.c	builtin/export.c	builtin/pwd.c	builtin/unset.c
LIBFT			:= libft/libft.a
OBJ = $(SRC:.c=.o);

# %.c : %.o
# $(CC) $(CFLAGS) -c $<



$(NAME) : $(OBJ)
	make -C libft bonus
	$(CC) $(CFLAGS) -o $(NAME) $(READLINE_LIB) $(READLINE_INC) $(LIBFT) $(OBJ)   

clean :
	make -C libft fclean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus






# READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
# READLINE_INC	:=	-I$(shell brew --prefix readline)/include

#builtin/cd.c builtin/echo.c builtine/env.c \
#builtin/exit.c builtin/export.c builtin/pwd.c\


					
