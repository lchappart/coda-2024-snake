# Makefile

NAME = snake

SRCS = main.c\
	fonction.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -g -o $(NAME) `sdl2-config --cflags --libs` -lSDL2_image

fclean:
	rm -f $(NAME)

re: fclean all