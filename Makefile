##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Leo Fabre
##

NAME	=	navy

SRC	=	src/main.c \
		src/bit_receiver.c \
		src/bin.c \
		src/print_help.c \
		src/process_packet.c \
		src/send_packet.c \
		src/signal_handler.c \
		src/game_loop.c \
		src/get_string.c \
		src/check_win.c \
		src/print_map.c \
		src/end_print.c \
		src/value_return.c \
		src/init.c \
		src/list_tools.c \
		src/add_rm_elems.c \
		src/client/connect_to_server.c \
		src/client/start_client.c \
		src/client/print_client.c \
		src/server/print_server.c\
		src/server/start_server.c \
		src/server/wait_for_client.c \
		src/mapzer/edit.c \
		src/mapzer/four_strings.c \
		src/mapzer/map2df.c \
		src/errors/checks.c \
		src/errors/errors.c \
		src/errors/errors_bis.c \
		src/tools.c				\
		src/atk_def_c.c				\
		src/atk_def_s.c				\
		src/tools_bis.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	+=	-L ./lib/my -lmy -I ./inc/ -Wall -Wextra -pedantic

DFLAGS	=	-Wextra -Wall -pedantic -I ./inc/ -L /lib/my -lmy -g

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			$(RM) $(OBJ)
			make clean -C lib/my

fclean:		clean
			$(RM) $(NAME)
			make fclean -C lib/my

re:		fclean all

debug : re
		make debug -C lib/my
		gcc -o $(NAME) $(OBJ) $(DFLAGS)