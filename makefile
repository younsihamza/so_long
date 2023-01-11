CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
NAME = so_long
HEADER = so_long.h

files = check_rectungel.c chick_map.c find_map.c ft_itoa.c ft_putnbr_base.c ft_putnbr.c \
		get_next_line.c get_next_line_utils.c movment.c q.c so_long.c help_so_long.c help_drow_map.c

OBJECTS = $(files:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  $(OBJECTS) -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
re: fclean all