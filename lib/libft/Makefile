# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maumonte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 14:58:40 by maumonte          #+#    #+#              #
#    Updated: 2025/07/05 14:58:53 by maumonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAME_BONUS = bonus

CC = @cc

CFLAGS = -Wall -Wextra -Werror -I.

AR = @ar rcs

RM = @rm -f 

SRC = ft_bzero.c     ft_strchr.c     ft_memcpy.c \
      ft_isalnum.c   ft_strnstr.c    ft_memmove.c \
      ft_isalpha.c   ft_strlcat.c    ft_memchr.c \
      ft_isascii.c   ft_strncmp.c    ft_memset.c \
      ft_isdigit.c   ft_strlcpy.c    ft_calloc.c \
      ft_isprint.c   ft_memcmp.c     ft_split.c \
      ft_atoi.c      ft_strlen.c     ft_itoa.c  \
      ft_tolower.c   ft_strdup.c     ft_strmapi.c \
      ft_toupper.c   ft_strjoin.c    ft_striteri.c \
      ft_substr.c    ft_strtrim.c    ft_putchar_fd.c \
      ft_putstr_fd.c ft_putnbr_fd.c  ft_strrchr.c \
      ft_putendl_fd.c 

SRC_BONUS = ft_lstnew.c   ft_lstadd_front.c ft_lstsize.c \
	    ft_lstlast.c  ft_lstadd_back.c  ft_lstdelone.c \
	    ft_lstclear.c ft_lstiter.c      ft_lstmap.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libft.h
      
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)
	
$(NAME_BONUS): $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)
	
clean: 
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all
