# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashanbha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 14:06:31 by ashanbha          #+#    #+#              #
#    Updated: 2019/03/26 14:24:15 by ashanbha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = libfunc1.c libfunc2.c libfunc3.c libfunc4.c libfunc5.c conv1.c conv2.c  \
	   conv3.c conv4.c conv5.c conv6.c conv7.c conv8.c conv9.c conv10.c conv11.c \
	   conv12.c conv13.c conv14.c conv15.c conv16.c conv17.c conv18.c conv19.c \
	   flt1.c flt2.c flt3.c flt4.c flt5.c figures.c colors.c flags1.c flags2.c \
	   flags3.c ft_printf.c

OBJFS = $(patsubst %.c, %.o, $(SRCS))

INCLUDES = ft_printf.h

INCFLAGS = $(addprefix -I, $(dir $(INCLUDES)))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) $(INCFLAGS)
	ar rc $(NAME) $(OBJFS)
	RANLIB $(NAME)

clean:
	/bin/rm -f $(OBJFS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
