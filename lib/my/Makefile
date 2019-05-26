##
## EPITECH PROJECT, 2018
## PSU_my_popup_2018
## File description:
## Makefile
##

NAME 	= 	libmy.a

SRC 	= 	src/my_strlen.c \
			src/my_getnbr.c \
			src/my_printerr.c \
			src/my_putstr.c \
			src/my_putchar.c \
			src/my_put_nbr.c \
			src/my_put_nbr_base.c \
			src/my_put_un_nbr_base.c \
			src/my_str_isnum.c \
			src/my_strlen.c \
			src/print_bin.c \
			src/print_char.c \
			src/print_int.c \
			src/print_octal.c \
			src/print_ptr.c \
			src/print_str.c \
			src/print_hexa.c \
			src/print_m_hexa.c \
			src/print_mod.c \
			src/match_args.c \
			src/my_printf.c \
			src/my_strncpy.c \
			src/my_strcmp.c \
			src/my_upperstr.c \
			src/my_atoi.c \
			src/my_strcat.c \
			src/my_strcpy.c \
			src/my_memset.c \
			src/my_strcontains.c \
			src/my_str_isempty.c \
			src/my_split.c \
			src/my_str_isalpha.c

OBJECTS = 	$(SRC:.c=.o)

CFLAGS 	= 	-I include/

CC 		= 	gcc

all: 	$(OBJECTS)
	 	ar rc $(NAME) $(OBJECTS)

clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)

re: 	fclean all
