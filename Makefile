# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artberna <artberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:40:40 by artberna          #+#    #+#              #
#    Updated: 2024/07/15 16:40:26 by artberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************
#                                    MAIN                                     *
#******************************************************************************

NAME = push_swap
HEADER = push_swap.h

#******************************************************************************
#                                 DIRECTORIES                                 *
#******************************************************************************

OBJ_DEP_DIR = obj_dep/
SRC_DIR = src/
MY_LIBRARY = my_library

#******************************************************************************
#                       SOURCES, OBJECTS & DEPENDENCIES                       *
#******************************************************************************

PUSH_SWAP_SRC = set_values_II set_values_III petit_sort grand_sort utils set_values main chained_list manage_input move_p1 move_p2 move_p3 move_p4 move_p5

PUSH_SWAP_FLS = $(addsuffix .c, $(PUSH_SWAP_SRC))

SRC = $(PUSH_SWAP_FLS)

OBJ = $(addprefix $(OBJ_DEP_DIR), $(SRC:.c=.o))

OBJF = .cache_exists

DEP = $(addprefix $(OBJ_DEP_DIR), $(OBJ:.o=.d))

#******************************************************************************
#                                INSTRUCTIONS                                 *
#******************************************************************************

CC = cc -g3
FLAGS = -Wall -Wextra -Werror -I.
RM = rm -rf
AR = ar rcs
LIB_FLAGS = -L./$(MY_LIBRARY) -l:my_library.a

#******************************************************************************
#                                  COLORS                                     *
#******************************************************************************

RESET = \033[0m
ROSE = \033[1;38;5;225m
VIOLET = \033[1;38;5;55m
VERT = \033[1;38;5;85m
BLEU = \033[1;34m

#******************************************************************************
#                                COMPILATION                                  *
#******************************************************************************

all : $(NAME)
	@echo "$(ROSE)COMPILATION FINISHED, $(NAME) IS CREATED!$(RESET)"

$(NAME) : $(OBJ) | $(MY_LIBRARY)/my_library.a
	@$(CC) $(FLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)

$(MY_LIBRARY)/my_library.a :
	@make -C $(MY_LIBRARY)

$(OBJ_DEP_DIR)%.o: %.c $(HEADER) | $(OBJF)
	@$(CC) $(FLAGS) -MMD -MP -c $< -o $@
	@echo "$(BLEU)Compiling $< to $@$(RESET)"

$(OBJF):
	@mkdir -p $(OBJ_DEP_DIR)

clean :
	@$(RM) $(OBJ_DEP_DIR)
	@make clean -C $(MY_LIBRARY)
	@echo "$(VIOLET)Suppressing objects & dependencies files of $(NAME)$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@rm -f $(MY_LIBRARY)/my_library.a
	@echo "$(VERT)Suppressing archives $(MY_LIBRARY).a$(RESET)"
	@echo "$(VERT)Suppressing archives $(NAME)$(RESET)"

re : fclean all

-include $(DEP)

.PHONY : re fclean clean all
