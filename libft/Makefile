# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:39:38 by ple-lez           #+#    #+#              #
#    Updated: 2022/12/16 11:18:09 by ple-lez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
DYNAMIC=libft.so

SRCS=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_atof.c \
	ft_toupper.c ft_tolower.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_memmove.c ft_atoi.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_atod.c

SRCS_BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c \
	get_next_line_utils.c ft_itoa_base.c ft_convert.c ft_check_args.c \
	ft_pad_int.c ft_pad_str.c ft_padding.c ft_printf.c ft_printf_parsearg.c \
	ft_printf_parsenum.c ft_printf_parsespec.c ft_printf_printarg.c ft_dlist_create.c \
	ft_dlist_add_front.c ft_dlist_add_back.c ft_dlist_pop.c ft_dlist_pop_back.c \
	ft_dlist_is_asc_sorted.c ft_dlist_foreach.c ft_dlist_swap.c ft_dlist_rotate.c \
	ft_dlist_clear.c ft_dlist_rev_rotate.c ft_dlist_push.c ft_dlist_find.c

INC_DIR=./

OBJS=${SRCS:.c=.o}
OBJS_BONUS=${SRCS_BONUS:.c=.o}

CC=gcc
FLAGS=-Wall -Wextra -Werror

RM=rm -f
AR=ar rc

all: $(NAME)

${NAME}: ${OBJS} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS} ${OBJS_BONUS}

.c.o:
	${CC} ${FLAGS} -I${INC_DIR} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}
	${RM} ${DYNAMIC}

re: fclean all

so:
	${CC} -nostartfiles -fPIC -c ${FLAGS} ${SRCS} ${SRCS_BONUS}
	${CC} -nostartfiles -shared -o ${DYNAMIC} ${OBJS} ${OBJS_BONUS}

bonus: ${OBJS} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS} ${OBJS_BONUS}

.PHONY: all clean fclean re rebonus
.SILENT :
