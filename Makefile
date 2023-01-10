SRCS_LIBFT	= ft_isdigit.c			\
			  ft_atoi.c				\
			  ft_strcmp.c			\
			  ft_min.c				\
			  ft_itoa.c				\
			  ft_memset.c 			\
			  ft_strchr.c 			\
			  ft_strcpy.c 			\
			  ft_strlen.c 			\
			  ft_strncpy.c 			\
			  ft_toupper.c			\
			  ft_strtoupper.c		\
			  ft_uitoa.c			\
			  ft_memalloc.c			\
			  ft_bzero.c			\
			  ft_calloc.c			\
			  ft_strncat.c			\

SRCS_GNL	= get_next_line.c		\
			  get_next_line_utils.c	\

SRCS_PRINTF	= ft_printf.c			\
			  parse.c				\
			  print.c				\
			  util.c				\
			  mode.c				\
			  flags.c				\
			  padding.c				\
			  convert.c				\
			  sort.c				\

SRCS		= main.c				\
			  check_map.c			\
			  find_path.c			\
			  parse_map.c			\
			  display.c				\
			  events.c				\
			  utils.c				\
			#   game.c				\
			#   enemy.c				\

OBJS_LIBFT	= $(addprefix srcs/libft/, $(SRCS_LIBFT:.c=.o))

OBJS_GNL	= $(addprefix srcs/gnl/, $(SRCS_GNL.c=.o))

OBJS_PRINTF	= $(addprefix srcs/printf/, $(SRCS_PRINTF:.c=.o))

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
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -lXext -lX11 -o $(NAME) 

$(LIBFT):	$(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRINTF)
	$(AR) $@ $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRINTF)

all:		$(NAME)

bonus:		all

clean:
	$(RM) $(OBJS) $(OBJS_LIBFT) $(OBJS_PRINTF)

fclean:		clean
	$(RM) $(NAME) $(LIBFT)

re:		fclean all

.PHONY:		all bonus clean fclean re
