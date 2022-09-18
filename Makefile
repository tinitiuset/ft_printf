NAME= libftprintf.a

SRC =	ft_printf.c ft_putnbr_base.c\
  		libft/ft_itoa.c libft/ft_strlen.c\
		libft/ft_strdup.c libft/ft_memcpy.c

LIBFT = libft/libft.a

OBJS = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	@#make bonus -C libft
	@ar rcs $(NAME) $(OBJS)
	@#gcc $(FLAGS) -o $(NAME)  $(SRC) $(LIBFT)
	@echo "Compiled"
clean:
	@rm -rf $(OBJS)
	@make clean -C libft
	@echo "Removed .o files"

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "Binary removed"

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
