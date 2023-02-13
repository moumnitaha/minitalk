# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 11:54:58 by tmoumni           #+#    #+#              #
#    Updated: 2023/02/12 16:50:48 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

HEADER = minitalk.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

S_SRC = server.c utils.c

C_SRC = client.c utils.c

all: $(SERVER) $(CLIENT)
	@echo "Client and Server created successfully!"

$(CLIENT): $(C_SRC) $(HEADER)
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) $(C_SRC) -o $(CLIENT)

$(SERVER): $(S_SRC) $(HEADER)
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) $(S_SRC) -o $(SERVER)

bonus: $(SERVER) $(CLIENT)
	@echo "Client and Server created successfully!"

clean: 
	@rm $(SERVER) $(CLIENT)

fclean:
	@rm $(SERVER) $(CLIENT)

re: clean all

.PHONY: all clean re