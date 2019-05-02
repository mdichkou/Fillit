NAME= fillit
SRC= ./*.c
LIBFT= ./libft/*.c

all:$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(LIBFT)
	ar rc ./libft/libft.a ./*.o	
	gcc -Wall -Wextra -Werror $(SRC) ./libft/libft.a -o $(NAME)
clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a
	
re:fclean all
