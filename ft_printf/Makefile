SRCS		=	ft_flags.c ft_parser.c ft_printf.c ft_proc_hexa.c ft_proc_hexa_X.c \
			ft_proc_char.c ft_proverka.c utils.c ft_proc_int.c ft_proc_pnt.c \
			ft_proc_uint.c ft_proc_string.c ft_proc_percent.c utils_two.c \
			hexa_dis.c proc_hexa.c proc_hexa_two.c ft_case_flags.c \
			proc_pointer.c ft_case_flags.c proc_pnt_case_two.c proc_pnt.c \
			proc_X.c proc_hexa_X.c int.c int_case_two.c int_case_three.c \
			uint_case_one.c uint_case_two.c str_case_one.c str_case_two.c
OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	=	$(BONUS:.c=.o)
INCS		=	ft_printf.h
NAME		=	libftprintf.a
GCC			=	gcc
ARRC		=	ar rc
RLIB		=	ranlib
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
.c.o:
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all:			${NAME}

${NAME}:		${OBJS}
				${ARRC} ${NAME} ${OBJS}
				${RLIB} ${NAME}


clean:
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all