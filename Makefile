CC=cc
FLAGS= -Wall -Werror -Wextra 
RM=rm -rf
FILES=mandelbrot.c julia.c fractal.c hook.c render.c
INC=fractol.h
NAME=Fractol
OBJ=$(FILES:.c=.o)


all: $(NAME)
	

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx  -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -c $<

clean:
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, temporary, norme, clean, fclean, re