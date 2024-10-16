# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laura <laura@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/18 18:53:32 by laura         #+#    #+#                  #
#    Updated: 2024/10/15 14:16:56 by laura         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------Executable
NAME	:= RPN

#----------------------------------------------------------------------Compiler
CC 		=  c++

#-------------------------------------------------------------------------Flags
CFLAGS	+= -Wextra -Wall -Werror -std=c++17
ASANFLAGS += -g -fsanitize=address -fsanitize=leak

#----------------------------------------------------------------Libraries path

#-----------------------------------------------------------------------Headers
HEADER	= RPN.h
#---------------------------------------------------------------------Libraries

#------------------------------------------------------------------------Source
SRC	:= RPN.cpp \
		main.cpp
#-----------------------------------------------------------------------Objects
OBJS	:= ${SRC:.cpp=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/
OBJECTS_PREFIXED := $(addprefix $(OBJ_DIR), $(OBJS))

#-------------------------------------------------------------------------Rules
all: $(NAME)


$(OBJ_DIR)%.o : %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJECTS_PREFIXED)
	@$(CC) $(OBJECTS_PREFIXED) -o $(NAME)
	@echo "Amazing calculator is ready!"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
