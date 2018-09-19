NAME		= Lem-in
FILENAMES 	= main.c \
			  create_node.c \
			  create_graph.c \
			  create_stack.c \
			  edge.c \
			  append.c \
			  dump.c \
			  free_all.c \
			  find.c \
			  dft.c \
			  errors.c \
			  map.c \

HDIR     	= ./includes
SDIR     	= ./src/
LDIR        = ./libft/
ODIR     	= ./obj
SRC      	= $(addprefix $(SDIR)/, $(FILENAMES))
OBJ      	= $(addprefix $(ODIR)/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re

CC       	= gcc
HFLAGS   	= -I $(HDIR)
LFLAGS      = -L $(LDIR) -lft
CFLAGS   	= -Wall -Werror -Wextra $(HFLAGS)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LDIR)
	@$(CC) -o $(@) $? $(HFLAGS) $(LFLAGS)
	@echo "\033[1;32;40mDone making Lem-in! \033[0m"

$(ODIR)/%.o : $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -o $@ -c -ggdb3 $?

clean:
	@echo removing objects...
	@rm -f $(OBJ)
	@rm -rf $(ODIR)
	@rm -rf Lem-in.dSYM/
	@echo Done!
fclean: clean
	@make fclean -C $(LDIR) 
	@echo removing binary files...
	@rm -f $(NAME)
	@echo Done!
re: fclean all

norm: 
	norminette ./src/
	norminette ./includes/
