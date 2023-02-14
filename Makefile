# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 11:54:58 by tmoumni           #+#    #+#              #
#    Updated: 2023/02/14 12:08:13 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

HEADER = minitalk.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

S_SRC = server.c

C_SRC = client.c

S_OBJ = $(S_SRC:%.c=%.o)
C_OBJ = $(C_SRC:%.c=%.o)

all: $(SERVER) $(CLIENT)
	@echo "Client and Server created successfully!"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "Compiling:" $< "..."

$(CLIENT): $(C_SRC) $(HEADER) $(C_OBJ)
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) $(C_OBJ) utils.c -o $(CLIENT)

$(SERVER): $(S_SRC) $(HEADER) $(S_OBJ)
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) $(S_OBJ) utils.c -o $(SERVER)

bonus: $(SERVER) $(CLIENT)
	@echo "Client and Server created successfully!"

clean:
	@rm -f $(S_OBJ) $(C_OBJ)

fclean:
	@rm -f $(SERVER) $(CLIENT) $(S_OBJ) $(C_OBJ)

re: fclean all

.PHONY: all clean re