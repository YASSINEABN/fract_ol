CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fract_ol
SRC = fract_ol.c render_Mandelbrot.c utils.c render_julia.c
OBJS = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} libmlx_Linux.a -lX11 -lXext -o ${NAME} 


clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
