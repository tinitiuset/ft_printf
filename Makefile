NAME= libftprintf.a

SRC =	ft_printf.c ft_putnbr_base.c\
  		libft/ft_strlen.c ft_long_itoa.c

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Compiled"
clean:
	@rm -rf $(OBJS)
	@echo "Removed .o files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed .a file"

re: fclean $(NAME)

.PHONY: all clean fclean re
