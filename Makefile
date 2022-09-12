NAME= libftprintf.out

SRC = main.c ft_printf.c

#OBJS = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	@#ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) -o $(NAME)  $(SRC)
	@echo "Compiled"
clean:
	@#rm -rf $(OBJS)
	@echo "Removed .o files"

fclean: clean
	rm -rf $(NAME)
	@echo "Binary removed"

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
