# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 09:10:09 by sprodatu          #+#    #+#              #
#    Updated: 2024/04/19 09:03:02 by sprodatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

CFLAGS := -Wall -Wextra -Werror

LDFLAGS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit -LMLX42/build -lmlx42

LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDE := -L $(LIBFT) -lft

LIBMLX := MLX42

SRCDIR := .

OBJDIR := obj

INCDIR := include

LIBDIR := MLX42/build

# Source files and object files
SRC := fractol.c drawing.c decimals.c ft_putstr.c i_like_to_moveit_moveit.c let_me_burn_ships.c

OBJ := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

# Target executable
TARGET := fractol

# Default target
all: libmlx $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

bonus: all

libmlx:
	git clone https://github.com/codam-coding-college/MLX42.git
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	rm -rf $(OBJDIR)
	rm -rf MLX42

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
