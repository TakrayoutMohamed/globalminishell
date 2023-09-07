NAME=minishell
LIBMINI=./execution/libmini.a
LIBFT=./execution/libft/libft.a
LIBPARS=./parsing/libpars.a
CC=cc
# CFLAGS=
CFLAGS=-Wall -Werror -Wextra
RM=rm -f
HEADERS=./libglobalminishell.h
SRC= convert_parsing_lst_to_execution.c convert_parsing_env_to_execution.c
MAIN_SRC=main.c

OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

READLINE_INC = -I/goinfre/$(USER)/.brew/opt/readline/include
READLINE_LIB = -lreadline -L/goinfre/$(USER)/.brew/opt/readline/lib

all:$(NAME)

$(NAME) :$(OBJ) $(MAIN_OBJ) $(LIBFT) $(LIBPARS) $(LIBMINI)
		make -C ./execution/libft all
		make -C ./parsing all
		make -C ./execution all
		$(CC)  -o $@ $(MAIN_OBJ) $(OBJ) $(LIBMINI) $(LIBFT) $(LIBPARS)  $(READLINE_LIB) 
		@echo "the executable $@ has been created"


%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) $(READLINE_INC) -o $@ -c $< 
		@echo "object $@ has been created from $<"

$(LIBFT):
		make -C ./execution/libft all
$(LIBPARS):
		make -C ./parsing all
$(LIBMINI):
		make -C ./execution all

clean:
	$(RM) $(MAIN_OBJ) $(LIBFT) $(OBJ) $(LIBPARS) $(LIBMINI)
	make -C ./execution clean
	make -C ./parsing clean

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	make -C ./execution fclean
	make -C ./parsing fclean
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
