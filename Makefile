NAME		= server

NAME1		= client

SRC0		= server.c

SRC1		= client.c

OBJ0		= $(SRC0:.c=.o)

OBJ1		= $(SRC1:.c=.o)

SRC0_B		= server_bonus.c

SRC1_B		= client_bonus.c

OBJ0_B		= $(SRC0_B:.c=.o)

OBJ1_B		= $(SRC1_B:.c=.o)

CFLAGS		= -Wextra -Wall -Werror

CC			= gcc

LIB_LIBFT	= -L libft -lft

INCLUDES	= -I libft/includes

all: $(NAME) $(NAME1)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC0) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ0) $(LIB_LIBFT)

$(NAME1):
	$(CC) $(CFLAGS) -c $(SRC1) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LIB_LIBFT)

bonus: server_bonus client_bonus

server_bonus:
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC0_B) $(INCLUDES)
	$(CC) $(CFLAGS) -o server_bonus $(OBJ0_B) $(LIB_LIBFT)

client_bonus:
	$(CC) $(CFLAGS) -c $(SRC1_B) $(INCLUDES)
	$(CC) $(CFLAGS) -o client_bonus $(OBJ1_B) $(LIB_LIBFT)

clean:
	make clean -C libft/
	rm -f $(OBJ0)
	rm -f $(OBJ1)
	rm -f $(OBJ0_B)
	rm -f $(OBJ1_B)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f $(NAME1)
	rm -f server_bonus
	rm -f client_bonus

re: fclean all

.PHONY: all clean fclean re
