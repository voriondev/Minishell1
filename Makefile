##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## MAKEFILE
##

NAME 	= 	mysh

SRC 	= 	src/main.c \
			src/env_manager.c \
			src/my_shell.c \
			src/get_input.c \
			src/prompt_loop.c \
			src/command_interpreter.c \
			src/copy_env.c \
			src/env_checker.c \
			src/parse_path_variable.c \
			src/check_signal.c \
			src/run_binary_file.c \
			src/builtins/cd.c \
			src/builtins/env.c \
			src/builtins/exit.c \
			src/builtins/setenv.c \
			src/builtins/unsetenv.c

OBJECTS	=	$(SRC:.c=.o)

LIBPATH = 	./lib/my

CFLAGS 	= 	-Wall -Wextra -Wshadow -I include/

LDFLAGS = 	-L $(LIBPATH) -lmy

CC 	= 	gcc

all: 	$(OBJECTS)
	$(MAKE) -C $(LIBPATH)
	cp $(LIBPATH)/include/my.h include/
	$(CC) $(OBJECTS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJECTS)
	$(MAKE) -C $(LIBPATH) clean

fclean: clean
	$(MAKE) -C $(LIBPATH) fclean
	$(RM) $(NAME)

re: 	fclean all
