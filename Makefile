EXECUTABLE = push_swap

FILES = push_swap.c \
		parsing/test.c\
		parsing/parsing_utils.c \
		parsing/parsing.c \
		lst_utils.c \
		lst_manip.c \
		free_and_exit.c \
		algo.c \
		target.c \
		commandes/commande_ps.c \
		commandes/commande_rotate.c \
		commandes/commande_rev_rotate.c \


LIBFT = lib_ft/libft.a

COMPIL = cc

FLAGS = -Wall -Werror -Wextra -g

HEADER_F = push_swap.h

O = ${FILES:.c=.o}

%.o: %.c
	${COMPIL} ${FLAGS} -c $< -o $@

${EXECUTABLE} : ${O} ${HEADER_F} ${LIBFT}
	${COMPIL} ${FLAG} -o ${EXECUTABLE} ${O}	${LIBFT}

${LIBFT}: 
	make -C lib_ft

all : ${EXECUTABLE}

clean :
	rm -f ${O}
	make -C lib_ft clean

fclean : clean
	rm -f ${EXECUTABLE}
	make -C lib_ft fclean

re : fclean all

.PHONY : all clean fclean re