# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:44:09 by sgabsi            #+#    #+#              #
#    Updated: 2023/11/17 12:54:47 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Sources
SRCDIR		=	./
SRC			=	ft_atoi.c 			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_itoa.c			\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_tolower.c		\
				ft_toupper.c	

SRCBONUS	=	ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c

# Objects
OBJDIR		=	obj
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)
BOBJ		=	$(SRCBONUS:%.c=$(OBJDIR)/%.o)

# Includes
INC			=	libft.h

# Output
NAME		=	libft.a
NAMESO		=	libft.so

# Compiler
CFLAGS		=	-Wall -Werror -Wextra
CC			=	cc
OPTIONS		=	-I $(INC)

# Couleurs
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

#################
##  TARGETS    ##
#################

all: pre_comp $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BOBJ)

pre_comp :
	@echo "$(YELLOW)********* Début de la compilation de la librairie Libft *********$(NC)"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)********* Compilation terminée avec succès! *********$(NC)"
	@echo "$(GREEN)********* La librairie $(NAME) a été créée. *********$(NC)"
	
bonus: $(BOBJ)
	@ar rc $(NAME) $(BOBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)**** Compilation des bonus terminée avec succès! ****$(NC)"
	@echo "$(GREEN)********* La librairie $(NAME) a été créée. *********$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAMESO) a.out
	@echo "$(RED)********* Suppression de la librairie $(NAME) *********$(NC)"
	
re: fclean all

.PHONY: all bonus clean fclean re