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
			  ft_memcpy.c			\
			  ft_strjoin.c			\
			  get_next_line.c		\

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
			  map_check.c			\
			  map_char.c			\
			  map_path.c			\
			  map_parse.c			\
			  display.c				\
			  events.c				\
			  utils.c				\
			  score.c				\

SRCS_BONUS	= main_bonus.c			\
			  map_check_bonus.c		\
			  map_char_bonus.c		\
			  map_path_bonus.c		\
			  map_parse_bonus.c		\
			  display_bonus.c		\
			  events_bonus.c		\
			  enemy_bonus.c			\
			  attack_bonus.c		\
			  score_bonus.c			\
			  utils_bonus.c			\

OBJS_LIBFT	= $(addprefix srcs/libft/, $(SRCS_LIBFT:.c=.o))

OBJS_PRINTF	= $(addprefix srcs/printf/, $(SRCS_PRINTF:.c=.o))

OBJS		= $(addprefix srcs/mandatory/, $(SRCS:.c=.o))

OBJS_BONUS	= $(addprefix srcs/bonus/, $(SRCS_BONUS:.c=.o))

DEP			= $(OBJS_LIBFT:.o=.d)	\
			  $(OBJS_PRINTF:.o=.d)	\
			  $(OBJS:.o=.d)			\
			  $(OBJS_BONUS:.o=.d)

LIBFT		= libft.a

INC			= -I include/ -I mlx/

CC			= cc

AR			= ar rcs

CFLAGS		= -g3 -Wall -Wextra -Werror -MMD

MLX_MAC		= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit

MLX			= -Lmlx -lmlx -lXext -lX11

RM			= rm -f

NAME		= so_long

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) 

$(LIBFT):	$(OBJS_LIBFT) $(OBJS_PRINTF)
	$(AR) $(LIBFT) $(OBJS_LIBFT) $(OBJS_PRINTF)

all:		$(NAME)

bonus:		$(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_PRINTF) $(DEP)

fclean:		clean
	$(RM) $(NAME) $(LIBFT)

re:		fclean all

-include : $(DEP)

.PHONY:		all bonus clean fclean re
