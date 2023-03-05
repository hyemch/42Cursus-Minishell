CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror

NAME	= 	minishell

LIB		=	./libft
LIBFT	=	ft

INC_DIR	=	-I.

INC		=	$(INC_DIR)/minishell.h

SRC		=	builtin.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	make -C $(LIB)
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) -o $(NAME) -L$(LIB) -l$(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean	:
	$(RM) $(OBJ)
	make clean -C $(LIB)

fclean	: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	make fclean -C $(LIB)

re :
	make fclean
	make all

.PHONY : all clean fclean re
