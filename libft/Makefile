
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

SRC = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c \
	ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_putstr_fd.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_memcpy.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_print_uni.c ft_print_ptr.c ft_print_int.c ft_print_char.c ft_print_str.c \
	ft_print_base.c ft_printf.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)




all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lft -o test
	./test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test

re: fclean all

