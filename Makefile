NAME =			libftprintf.a

HEADER =		includes/ft_printf.h
SRCS =			ft_printf.c
SRCS_OBJS =		${SRCS:.c=.o}

UTILS =			ft_calloc.c \
				ft_itoa_base.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strlen.c
UTILS_DIR =		utils/
UTILS_SRCS = 	${addprefix ${UTILS_DIR},${UTILS}}
UTILS_OBJS =	${UTILS_SRCS:.c=.o}

HANDLERS =		ft_handler_character.c \
				ft_handler_decimal.c \
				ft_handler_hex_lower.c \
				ft_handler_hex_upper.c \
				ft_handler_percent.c \
				ft_handler_pointer.c \
				ft_handler_string.c \
				ft_handler_unsigned.c
HANDLERS_DIR =	handlers/
HANDLERS_SRCS =	${addprefix ${HANDLERS_DIR},${HANDLERS}}
HANDLERS_OBJS =	${HANDLERS_SRCS:.c=.o}

RM =			rm -f
CC =			cc -Wall -Wextra -Werror
AR =			ar -rcs

all:			${NAME}

${NAME}:		${SRCS_OBJS} ${UTILS_OBJS} ${HANDLERS_OBJS} ${HEADER} Makefile
				@${AR} ${NAME} ${SRCS_OBJS} ${UTILS_OBJS} ${HANDLERS_OBJS}
				@echo [SUCCESS] Library creation done!

.c.o:
				@${CC} -I includes/ -c $< -o $@
				@echo [SUCCESS] $@ creation done!

clean:
				@${RM} ${SRCS_OBJS} ${UTILS_OBJS} ${HANDLERS_OBJS}
				@echo [SUCCESS] Objects removal done!

fclean:			clean
				@${RM} ${NAME}
				@echo [SUCCESS] Library removal done!

re:				fclean all

.PHONY:			all clean fclean re
