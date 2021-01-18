# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclock <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 13:39:14 by cclock            #+#    #+#              #
#    Updated: 2021/01/06 04:23:27 by cclock           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fill_flag_width_precision_type.c \
	   ft_printf.c \
	   parse_and_print.c \
	   parse_and_print_sec.c \
	   print_d.c \
	   print_x.c \
	   print_un.c \
	   print_d_second.c \
	   fill_flag_width_sec.c \
	   convert_x.c

OBJS = $(SRCS:.c=.o)

ARRC = ar rcs

NAME = libftprintf.a

LIBFT = ./libft/

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: compile_lib $(NAME) $(HEADER)

$(NAME): $(OBJS) $(HEADER)
		$(ARRC) $(NAME) $(OBJS) ./libft/*.o

compile_lib:
	make -C $(LIBFT)

.c.o:
		gcc $(FLAGS) -c -I $(HEADER) $< -o $(<:.c=.o)

clean:
		rm -rf $(OBJS)
		make clean -C $(LIBFT)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
