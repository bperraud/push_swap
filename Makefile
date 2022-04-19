# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 16:51:35 by bperraud          #+#    #+#              #
#    Updated: 2022/04/19 03:01:16 by bperraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### SOURCES FILES ###
SRC				= main.c linked_list.c linked_list_2.c utils.c operation.c check.c push_swap.c optimisation.c sort.c list_utils.c

#BONUS			= checker.c linked_list.c linked_list_2.c utils.c operation.c check.c push_swap.c optimisation.c sort.c list_utils.c

BONUS			= get_next_line.c get_next_line_utils.c checker.c linked_list.c linked_list_2.c utils.c operation.c check.c push_swap.c optimisation.c sort.c list_utils.c

### PATHS ###
SDIR			= src
HDIR			= include
ODIR			= objs

### OBJECTS ###
OBJ	  			= $(addprefix $(ODIR)/, $(SRC:.c=.o))
BONUS_OBJ		= $(addprefix $(ODIR)/, $(BONUS:.c=.o))

### COMPILATION ###
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Iinclude
RM				= rm -f

### EXECUTABLE ###
NAME			= push_swap
NAMEB			= checker

### LINK ###
$(NAME):		$(OBJ)
				$(MAKE) -C ./libft
				$(CC) $(OBJ)  libft/libft.a -o $(NAME)

$(NAMEB):		$(BONUS_OBJ)
				$(MAKE) -C ./libft
				$(CC) $(BONUS_OBJ)  libft/libft.a -o $(NAMEB)

### OBJECTS ###
$(ODIR)/%.o: 	$(SDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus:			tmp $(NAMEB)

all:			tmp $(NAMEB)

tmp:
				mkdir -p objs

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME) $(NAMEB)

re:				fclean $(NAME) $(NAMEB)

.PHONY:			all clean fclean re
