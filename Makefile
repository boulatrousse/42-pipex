.PHONY:								all $(NAME) clean fclean re mkbuild lib

GREEN								= \033[1;32m
PURPLE								= \033[1;35m
END									= \033[0m

NAME								= pipex

BUILD_DIR							= build/

HEADER_DIR							= header/
HEADER_FILE							= pipex.h

DIR									= src/
SRC									= 	main.c \
										utils.c \
										commands.c \
										close.c \
										error.c \

OBJECTS								= $(SRC:%.c=$(BUILD_DIR)%.o)

LIBFT								= libft.a
LIB_DIR								= libft/

GCC									= gcc

CFLAGS								= -Wall -Werror -Wextra

RM									= rm -rf

$(BUILD_DIR)%.o:					$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) $(LIBFT) $(LIB_DIR) Makefile
										@mkdir -p $(@D)
										$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I/usr/include -c $< -o $@

all:								mkbuild lib $(HEADER_DIR) $(NAME)

mkbuild:							
										@mkdir -p build

lib:								
										@make -C $(LIB_DIR)
										

$(NAME):							$(OBJECTS)
										@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)
										@echo "$(GREEN)[LIBFT OK] $(END)"
										@echo "$(PURPLE)[PIPEX IS READY] $(END)"
										
clean:							
										@$(RM) $(OBJECTS)
										@make clean -C $(LIB_DIR)
										@$(RM) $(BUILD_DIR)
										@echo "$(GREEN)[CLEAN DONE] $(END)"

fclean:								clean
										@$(RM) $(NAME) 
										@make fclean -C $(LIB_DIR)
										@echo "$(GREEN)[FCLEAN DONE] $(END)"

re:									fclean all
										@$(MAKE) all -silent
										@echo "$(PURPLE)[REMAKE DONE] $(END)"