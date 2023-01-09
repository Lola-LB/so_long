SRCS_LIBFT	= ft_isdigit.c		\
			  ft_atoi.c			\
			  ft_strcmp.c		\
			  ft_min.c			\
			  ft_itoa.c			\
			  ft_memset.c 		\
			  ft_strchr.c 		\
			  ft_strcpy.c 		\
			  ft_strlen.c 		\
			  ft_strncpy.c 		\
			  ft_toupper.c		\
			  ft_strtoupper.c	\
			  ft_uitoa.c		\

SRCS_PRINTF	= ft_printf.c		\
			  parse.c			\
			  print.c			\
			  util.c			\
			  mode.c			\
			  flags.c			\
			  padding.c			\
			  convert.c			\
			  sort.c			\

SRCS		= check_map.c		\
			  main.c			\
			  utils.c			\
			#   walls.c			\
			#   enemy.c			\
			#   init.c			\

OBJS_LIBFT	= $(addprefix libft/, $(SRCS_LIBFT:.c=.o))

OBJS_PRINTF	= $(addprefix printf/, $(SRCS_PRINTF:.c=.o))

OBJS		= $(addprefix srcs/, $(SRCS:.c=.o))

LIBFT		= libft.a

INC			= -I include/

INC_MLX		= -I mlx/

CC			= cc

AR			= ar rcs

CFLAGS		= -g3 -Wall -Wextra -Werror

MLX			= -lm -framework OpenGL -framework AppKit

RM			= rm -f

NAME		= so_long

%.o: %.c
	$(CC) $(CFLAGS) $(INC_MLX) $(INC) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(LIBFT):	$(OBJS_LIBFT) $(OBJS_PRINTF)
	$(AR) $@ $^

all:		$(NAME)

bonus:		all

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
