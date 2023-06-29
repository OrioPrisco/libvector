# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 15:27:59 by OrioPrisc         #+#    #+#              #
#    Updated: 2023/06/29 16:47:24 by OrioPrisco       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a
CC = cc
SRC =	vector.c\
		vector2.c\
		vector3.c\
		vector4.c\

SRC_FOLDER = srcs/

OBJ_FOLDER = objs/
HEADERS_FOLDER =	includes/\
					../includes/\


OBJS		=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))
COMMANDS	=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))
DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))

CFLAGS = -Wall -Wextra -Werror -fPIC

all: $(NAME) compile_commands.json
	

-include $(DEPENDS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c Makefile
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	@$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

clean:
	rm -f $(OBJS) $(DEPENDS) $(COMMANDS)

fclean: clean
	rm -f $(NAME) compile_commands.json

re: fclean all
	
.PHONY: all clean fclean re bonus so
.SUFFIXES:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
