# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/02 18:03:27 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 				:=	cc
CFLAGES 		:=	-Wall -Werror -Wextra
READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
READLINE_INC	:=	-I$(shell brew --prefix readline)/include
SRC				:=	builtin/cd.c builtin/echo.c builtine/env.c \
					builtin/exit.c builtin/export.c builtin/pwd.c
					
