# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/16 17:10:02 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:=	minishell
CC 				:=	cc
CFLAGES 		:=	-Wall -Werror -Wextra
READLINE_LIB	:=	-lreadline -Lreadline
READLINE_INC	:=	-I./readline
SRC 			:=	parser/tree.c \
					parser/utils.c			excute/excute.c			parser/search_tree.c \
					parser/utils2.c		parser/split_input.c	parser/valid_check.c	parser/token_check.c \
					prompt/prompt.c		parser/token_list.c		parser/parser.c			parser/token_list2.c \
					excute/excute.c \
					#builtin/builtin_list.c	builtin/cd.c				builtin/echo.c			builtin/env.c	builtin/exit.c	builtin/export.c	builtin/pwd.c	builtin/unset.c
LIBFT			:= libft/libft.a
OBJ 			:= $(SRC:.c=.o);


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


					
