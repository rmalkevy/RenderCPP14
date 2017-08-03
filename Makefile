# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/03/30 15:41:53 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RenderCPP

SRCCPP =		main.cpp \
				Render.cpp \
                Camera.cpp \
                Light.cpp \
                Sphere.cpp \
                Plane.cpp \
                Cylinder.cpp \
                Cone.cpp \
                Triangle.cpp \
                Vec3d.cpp \
                Window.cpp \
                KeyboardMouseControl.cpp



SRCMLX = minilibx/*.c

OBJCPP = $(SRCCPP:.cpp=.o)
OBJMLX = $(SRCMLX:.c=.o)

GPP = g++

FLGS = -Wall -Wextra -Werror -std=c++14 -g

LIBMLX = -L ./minilibx/ -lmlx
LIBCPP = -L ./includes/

all: $(NAME)

$(NAME): $(OBJCPP)
		make -C ./minilibx/
		$(GPP) -o $(NAME) $(OBJCPP) $(OBJMLX) $(LIBCPP) $(LIBMLX) -framework OpenGL -framework AppKit -g

%.o: %.cpp
		$(GPP) $(FLGS) -c $<

clean:
		make -C ./minilibx/ clean
		rm -rf $(OBJCPP)

fclean: clean
		rm -f $(NAME)

re: fclean all