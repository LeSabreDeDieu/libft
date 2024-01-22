# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:44:09 by sgabsi            #+#    #+#              #
#    Updated: 2024/01/22 14:35:30 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
SRCDIR		=	./srcs
INCDIR		=	./includes
OBJDIR		=	objs

# Sources
SRC_SUBDIRS	=	ft_is ft_lst ft_mem ft_put ft_str ft_to gnl printf
SRC_FILES	=	$(SRCDIR)/ft_is/ft_isalnum.c $(SRCDIR)/ft_is/ft_isalpha.c $(SRCDIR)/ft_is/ft_isascii.c \
				$(SRCDIR)/ft_is/ft_isdigit.c $(SRCDIR)/ft_is/ft_isprint.c \
				$(SRCDIR)/ft_lst/ft_lstadd_back.c $(SRCDIR)/ft_lst/ft_lstadd_front.c \
				$(SRCDIR)/ft_lst/ft_lstclear.c $(SRCDIR)/ft_lst/ft_lstdelone.c \
				$(SRCDIR)/ft_lst/ft_lstiter.c $(SRCDIR)/ft_lst/ft_lstlast.c \
				$(SRCDIR)/ft_lst/ft_lstmap.c $(SRCDIR)/ft_lst/ft_lstnew.c $(SRCDIR)/ft_lst/ft_lstsize.c \
				$(SRCDIR)/ft_mem/ft_bzero.c $(SRCDIR)/ft_mem/ft_calloc.c $(SRCDIR)/ft_mem/ft_memchr.c \
				$(SRCDIR)/ft_mem/ft_memcmp.c $(SRCDIR)/ft_mem/ft_memcpy.c \
				$(SRCDIR)/ft_mem/ft_memmove.c $(SRCDIR)/ft_mem/ft_memset.c \
				$(SRCDIR)/ft_put/ft_putchar_fd.c $(SRCDIR)/ft_put/ft_putendl_fd.c \
				$(SRCDIR)/ft_put/ft_putnbr_fd.c $(SRCDIR)/ft_put/ft_putstr_fd.c \
				$(SRCDIR)/ft_str/ft_split.c $(SRCDIR)/ft_str/ft_strchr.c \
				$(SRCDIR)/ft_str/ft_strdup.c $(SRCDIR)/ft_str/ft_striteri.c \
				$(SRCDIR)/ft_str/ft_strjoin.c $(SRCDIR)/ft_str/ft_strlcat.c \
				$(SRCDIR)/ft_str/ft_strlcpy.c $(SRCDIR)/ft_str/ft_strlen.c \
				$(SRCDIR)/ft_str/ft_strmapi.c $(SRCDIR)/ft_str/ft_strncmp.c \
				$(SRCDIR)/ft_str/ft_strnstr.c $(SRCDIR)/ft_str/ft_strrchr.c \
				$(SRCDIR)/ft_str/ft_strtrim.c $(SRCDIR)/ft_str/ft_substr.c \
				$(SRCDIR)/ft_to/ft_atoi.c $(SRCDIR)/ft_to/ft_itoa.c \
				$(SRCDIR)/ft_to/ft_tolower.c $(SRCDIR)/ft_to/ft_toupper.c \
				$(SRCDIR)/gnl/get_next_line.c $(SRCDIR)/gnl/get_next_line_utils.c \
				$(SRCDIR)/printf/ft_print_hex.c $(SRCDIR)/printf/ft_print_ptr.c \
				$(SRCDIR)/printf/ft_print_unsigned.c $(SRCDIR)/printf/ft_printf_utils.c \
				$(SRCDIR)/printf/ft_printf.c

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
GREEN		=	$(echo -e "\033[0;32m")
YELLOW		=	$(echo -e "\033[0;33m")
RED			=	$(echo -e "\033[0;31m")
NC			=	$(echo -e "\033[0m")

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
