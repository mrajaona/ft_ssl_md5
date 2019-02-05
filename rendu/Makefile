NAME		=	ft_ssl
INCLUDE		=	./inc/

INC			=	ft_ssl.h \
				util.h \
				parser.h \
				input.h \
				output.h \
				md5.h \
				sha256.h
INCS		=	$(addprefix $(INCLUDE), $(INC))

DIR_MAIN	=	./src/
SRC_MAIN	=	main.c
SRCS_MAIN	=	$(addprefix $(DIR_MAIN), $(SRC_MAIN))

DIR_UTIL	=	./src/util/
SRC_UTIL	=	rotate.c \
				ft_strlen.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_memcpy.c \
				ft_strdel.c \
				ft_memalloc.c \
				ft_gethex.c \
				ft_endian.c \
				get_next_line.c
SRCS_UTIL	=	$(addprefix $(DIR_UTIL), $(SRC_UTIL))

DIR_PARSER	=	./src/parser/
SRC_PARSER	=	parser.c
SRCS_PARSER	=	$(addprefix $(DIR_PARSER), $(SRC_PARSER))

DIR_INPUT	=	./src/input/
SRC_INPUT	=	input.c
SRCS_INPUT	=	$(addprefix $(DIR_INPUT), $(SRC_INPUT))

DIR_OUTPUT	=	./src/output/
SRC_OUTPUT	=	output.c \
				print_hash.c
SRCS_OUTPUT	=	$(addprefix $(DIR_OUTPUT), $(SRC_OUTPUT))

DIR_MD5		=	./src/md5/
SRC_MD5		=	md5.c \
				init.c \
				calc_loop.c \
				rounds.c \
				tostr.c
SRCS_MD5	=	$(addprefix $(DIR_MD5), $(SRC_MD5))

DIR_SHA256	=	./src/sha256/
SRC_SHA256	=	sha256.c \
				init.c \
				init_calc.c \
				calc_loop.c \
				tostr.c
SRCS_SHA256	=	$(addprefix $(DIR_SHA256), $(SRC_SHA256))

SRCS		=	$(SRCS_MAIN) \
				$(SRCS_UTIL) \
				$(SRCS_PARSER)\
				$(SRCS_INPUT) \
				$(SRCS_OUTPUT) \
 				$(SRCS_MD5) \
				$(SRCS_SHA256)

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror \
				-I $(INCLUDE)

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/usr/bin/printf

all		:		$(NAME)

$(OBJS)	:		$(INCS)

$(NAME)	:		$(INCS) $(SRCS) $(INCLUDE) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@$(ECHO) "\033[32m> Executable compiled\033[0m\n"

clean	:
				@$(RM) $(OBJS)
				@$(ECHO) "\033[31m> Directory cleaned\033[0m\n"

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) "\033[31m> Removed executable\033[0m\n"

re		:		fclean all

.PHONY	:		all clean fclean re

.DEFAULT_GOAL	:=	all
