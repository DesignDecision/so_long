CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= solong

LIB_PATH	= ./Libft
INCL_PATH	= ./Libft

LIBRARY		= libft.a

MINI_PATH	= ./minilibx-linux
MINI_INCL	= ./minilibx-linux

MAKE		= make

SRC			= exits.c loadmap.c loadtiles.c mapchecks.c movement.c so_long.c

OBJ			= ${SRC:.c=.o}

LINKS		= -I$(INCL_PATH) \
			-I$(MINI_INCL) \
			-L $(MINI_PATH) -lmlx \
			-L $(LIB_PATH) -lft \
			-lX11 -lXext -lm

all:		$(LIBRARY) $(NAME)


$(LIBRARY):
			$(MAKE) -C $(LIB_PATH)
			$(MAKE) -C $(MINI_PATH)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LINKS) 

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIB_PATH) fclean
			$(MAKE) -C $(MINI_PATH) clean

re:			fclean all
#Command runs norminette only for my files, not on mlx library
norm:
			norminette libft/
			norminette $(SRC) || true

.PHONY: all clean fclean re norm