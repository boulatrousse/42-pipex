# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:06:34 by lboulatr          #+#    #+#              #
#    Updated: 2023/02/23 14:40:41 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

SRCS                    = ft_atoi.c    ft_isascii.c    ft_memcmp.c    ft_putendl_fd.c \
                        ft_strdup.c    ft_strlen.c    ft_substr.c    ft_bzero.c    ft_isdigit.c \
                        ft_memcpy.c    ft_putnbr_fd.c    ft_striteri.c    ft_strmapi.c \
                        ft_tolower.c    ft_calloc.c    ft_isprint.c    ft_memmove.c \
                        ft_putstr_fd.c    ft_strjoin.c    ft_strnstr.c    ft_toupper.c \
                        ft_isalnum.c    ft_itoa.c    ft_memset.c    ft_split.c    ft_strlcat.c \
                        ft_strrchr.c    ft_isalpha.c    ft_memchr.c    ft_putchar_fd.c \
                        ft_strchr.c    ft_strlcpy.c    ft_strtrim.c    ft_strncmp.c \
                        ft_lstsize.c    ft_lstadd_front.c    ft_lstnew.c    ft_lstlast.c \
                        ft_lstadd_back.c    ft_lstdelone.c    ft_lstclear.c    ft_lstiter.c \
                        ft_lstmap.c

OBJS                    = $(SRCS:%.c=$(BUILD_DIR)%.o)

BUILD_DIR               = build/

CC                      = cc

HEADER                  = include/libft.h

FLAGS                   = -Wall -Wextra -Werror

NAME                    = libft.a

LIB                     = ar rc

RM                      = rm -rf

$(BUILD_DIR)%.o:        %.c $(HEADER) 
	 					    @mkdir -p $(@D)
						    ${CC} $(FLAGS) -include $(HEADER) -c $< -o $@

all:    			    $(NAME)    

$(NAME):    		    $(OBJS) 
					        $(LIB) $(NAME) $(OBJS) 

clean:
					        @$(RM) ${OBJS}
						    @$(RM) $(BUILD_DIR)

fclean:    			    clean
						    @${RM} ${NAME}

re:                     all fclean
