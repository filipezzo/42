NAME = libftprintf.a
AR = ar -rcs
RM = rm -f
CC = cc
CCFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
FILES = ft_print_char.c ft_print_hex.c ft_print_number.c ft_print_pointer.c ft_print_string.c ft_print_unsigned_decimal.c ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putunsigned.c ft_strlen.c
		

SRC = $(FILES)

OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
