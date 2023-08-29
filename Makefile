NAME=minishell
LIBMINI=./minishell1/libmini.a
LIBFT=./minishell1/libft/libft.a
LIBPARS=./USM4minishell/libpars.a
CC=cc
# CFLAGS=
CFLAGS=-Wall -Werror -Wextra
RM=rm -f
HEADERS=./libglobalminishell.h
SRC=
MAIN_SRC=main.c

OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

READLINE_INC = -I/goinfre/$(USER)/.brew/opt/readline/include		 	#MAC
READLINE_LIB = -lreadline -L/goinfre/$(USER)/.brew/opt/readline/lib    #MAC

all:$(NAME)

$(NAME) : $(MAIN_OBJ) $(LIBFT) $(LIBPARS) $(LIBMINI)
		$(CC)  -o $@ $(MAIN_OBJ) $(LIBFT) $(LIBPARS) $(LIBMINI) $(READLINE_LIB)
		@echo "the executable $@ has been created"


%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) $(READLINE_INC) -o $@ -c $< 
		@echo "object $@ has been created from $<"

$(LIBFT):
		make -C ./minishell1/libft all
$(LIBPARS):
		make -C ./USM4minishell all
$(LIBMINI):
		make -C ./minishell1 all

clean:
	$(RM) $(MAIN_OBJ) $(LIBFT) $(LIBPARS) $(LIBMINI)
	make -C ./../minishell1/libft clean

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	make -C ./../minishell1/libft fclean
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
