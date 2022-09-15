NAME= libftprintf.out

SRC = main.c ft_printf.c \
	ft_putnbr_base.c

#OBJS = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	@#ar rcs $(NAME) $(OBJS)
	@make bonus -C libft
	gcc $(FLAGS) -o $(NAME)  $(SRC) libft/libft.a
	@echo "Compiled"
clean:
	@#rm -rf $(OBJS)
	@make clean -C libft
	@echo "Removed .o files"

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "Binary removed"

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
