# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 11:54:58 by tmoumni           #+#    #+#              #
#    Updated: 2023/02/15 10:16:51 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

HEADER = minitalk.h
UTILS = utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

S_SRC = server.c
C_SRC = client.c

BS_SRC = server_bonus.c
BC_SRC = client_bonus.c

S_OBJ = $(S_SRC:%.c=%.o)
C_OBJ = $(C_SRC:%.c=%.o)

BS_OBJ = $(BS_SRC:%.c=%.o)
BC_OBJ = $(BC_SRC:%.c=%.o)

BOLD = \033[1m
END = \033[0m
GREEN=\033[1;32m
CYAN=\033[1;36m

all: $(SERVER) $(CLIENT)
	@echo "$(GREEN)client$(END) and $(GREEN)server$(END) created successfully!"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "Compiling:" $< "..."

$(CLIENT): $(C_SRC) $(HEADER) $(C_OBJ)
	@echo "Creating $(GREEN)client...$(END)"
	@$(CC) $(CFLAGS) $(C_OBJ) $(UTILS) -o $(CLIENT)

$(SERVER): $(S_SRC) $(HEADER) $(S_OBJ)
	@echo "Creating $(GREEN)server...$(END)"
	@$(CC) $(CFLAGS) $(S_OBJ) $(UTILS) -o $(SERVER)

bonus: $(BC_OBJ) $(BS_OBJ)
	@$(CC) $(CFLAGS) $(BC_OBJ) $(UTILS) -o $(CLIENT)
	@$(CC) $(CFLAGS) $(BS_OBJ) $(UTILS) -o $(SERVER)
	@echo "$(CYAN)BONUS:$(END) $(GREEN)client$(END) and $(GREEN)server$(END) created successfully!"

clean:
	@rm -f $(S_OBJ) $(C_OBJ) $(BC_OBJ) $(BS_OBJ)

fclean:
	@rm -f $(SERVER) $(CLIENT) $(S_OBJ) $(C_OBJ) $(BC_OBJ) $(BS_OBJ)

re: fclean all

.PHONY: all clean re