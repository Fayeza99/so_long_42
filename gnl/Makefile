NAME = get_next_line.a

CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
OBJ = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

fclean:
	rm -f $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	
re: fclean all