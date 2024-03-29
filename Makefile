CC = gcc
SRC =	*.c
MINILIBXPATH = ./mlx
LIBFTPATH = ./Libft
NAME = so_long
LIBRARY = libmlx.a

all: $(LIBRARY) libft.a $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlxmac -c $< -o $@

$(NAME): $(SRC)
	$(CC) -g -Lmlx -L $(MINILIBXPATH) -lmlx -framework OpenGL -framework AppKit -L $(LIBFTPATH) -lft $(SRC)


$(LIBRARY):
	make -C $(MINILIBXPATH)
	cp $(MINILIBXPATH)/$(LIBRARY) .
	cp $(MINILIBXPATH)/mlx.h .

libft.a:
	make -C $(LIBFTPATH)

archive:
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS) a.out mlx.h

fclean: clean
	/bin/rm -f $(NAME) $(LIBRARY)
	make -C $(LIBFTPATH) fclean
	make -C $(MINILIBXPATH) clean

re: fclean all