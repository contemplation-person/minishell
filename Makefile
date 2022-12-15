# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/15 15:46:36 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:= minishell
CC 				:=	cc
CFLAGES 		:=	-Wall -Werror -Wextra
READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
READLINE_INC	:=	-I$(shell brew --prefix readline)/include
SRC = prompt/prompt.c

OBJ = $(SRC:.c=.o);

# %.c : %.o
# $(CC) $(CFLAGS) -c $<


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus








#builtin/cd.c builtin/echo.c builtine/env.c \
#builtin/exit.c builtin/export.c builtin/pwd.c\


					
