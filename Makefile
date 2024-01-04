# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:44:09 by sgabsi            #+#    #+#              #
#    Updated: 2024/01/04 13:25:25 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
SRCDIR		=	./
INCDIR		=	./
OBJDIR		=	objs

# Sources
SRC_SUBDIRS	=	ft_is ft_lst ft_mem ft_put ft_str ft_to
SRC_FILES	=	ft_is/ft_isalnum.c ft_is/ft_isalpha.c ft_is/ft_isascii.c \
				ft_is/ft_isdigit.c ft_is/ft_isprint.c \
				ft_lst/ft_lstadd_back.c ft_lst/ft_lstadd_front.c \
				ft_lst/ft_lstclear.c ft_lst/ft_lstdelone.c \
				ft_lst/ft_lstiter.c ft_lst/ft_lstlast.c \
				ft_lst/ft_lstmap.c ft_lst/ft_lstnew.c ft_lst/ft_lstsize.c \
				ft_mem/ft_bzero.c ft_mem/ft_calloc.c ft_mem/ft_memchr.c \
				ft_mem/ft_memcmp.c ft_mem/ft_memcpy.c \
				ft_mem/ft_memmove.c ft_mem/ft_memset.c \
				ft_put/ft_putchar_fd.c ft_put/ft_putendl_fd.c \
				ft_put/ft_putnbr_fd.c ft_put/ft_putstr_fd.c \
				ft_str/ft_split.c ft_str/ft_strchr.c \
				ft_str/ft_strdup.c ft_str/ft_striteri.c \
				ft_str/ft_strjoin.c ft_str/ft_strlcat.c \
				ft_str/ft_strlcpy.c ft_str/ft_strlen.c \
				ft_str/ft_strmapi.c ft_str/ft_strncmp.c \
				ft_str/ft_strnstr.c ft_str/ft_strrchr.c \
				ft_str/ft_strtrim.c ft_str/ft_substr.c \
				ft_to/ft_atoi.c ft_to/ft_itoa.c \
				ft_to/ft_tolower.c ft_to/ft_toupper.c

# Objects
OBJ_SUBDIRS	=	$(SRC_SUBDIRS:%=$(OBJDIR)/%)
OBJ			=	$(SRC_FILES:%.c=$(OBJDIR)/%.o)

# Output
NAME		=	libft.a
NAMESO		=	libft.so

# Compiler
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -O3 -ffreestanding -nostdlib
OPTIONS		=	-I $(INCDIR)

#Progress bar
COUNT		=	1
TOTAL_FILES	=	$(shell find . -type f -name "*.c" | wc -l)

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
NC			=	\033[0m

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
	@ar rcs $(NAME) $(OBJ)
	@printf "\r% 200s"
	@echo "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)"
	@echo "$(GREEN)********* La librairie $(NAME) a été créée. *********$(NC)"
	
bonus: $(OBJ) $(BOBJ)
	@ar rcs $(NAME) $(OBJ) $(BOBJ)
	@echo "$(GREEN)**** Compilation des bonus terminée avec succès! ****$(NC)"
	@echo "$(GREEN)********* La librairie $(NAME) a été créée. *********$(NC)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ -c $<
	@printf "\rCompiling files: [%-50s] %3d%% (%d/%d) %s % 10s" \
		"$(shell printf '=%.0s' $$(seq 1 $$(($(COUNT) * 50 / $(TOTAL_FILES)))))" \
		$$(($(COUNT) * 100 / $(TOTAL_FILES))) \
		$(COUNT) \
		$(TOTAL_FILES) \
		$<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAMESO) a.out
	@echo "$(RED)********* Suppression de la librairie $(NAME) *********$(NC)"
	
re: fclean all

.PHONY: all bonus clean fclean re