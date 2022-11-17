NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR=./libft/
LIBFT_NAME=libft.a
LIB=$(LIB_DIR)$(LIBFT_NAME)
INCLUDE=-I ./libft
AR = ar
ARFLAGS = rcs
RM = rm -f
SRCS = ft_printf.c \
		print_specifier.c \
		print_char.c \
		print_decimal.c \
		print_integer.c \
		print_lower_hex.c \
		print_upper_hex.c \
		print_percent.c \
		print_pointer.c \
		print_string.c \
		print_unsigned_decimal.c \
		print_var.c \
		printf_utils.c \
		printf_utils2.c \
		get_option.c \
		num_to_str.c \
		num_len.c \
		alloc_num.c \
		free_mem.c

OBJS=$(SRCS:.c=.o)

$(NAME) : $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all

all : $(NAME)

bonus : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re bonus