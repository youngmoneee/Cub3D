NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

FRMWRK	= -framework Opengl -framework Appkit
MLX		= mlx
MLXDIR	= mlxdir

INC		= inc

SRCD	= src
SRCF	= main.c \
		  parse_1.c

SRCS	= $(addprefix $(SRCD)/, $(SRCF))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

all	:	$(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INC) -L$(MLXDIR) -l$(MLX) $(FRMWRK) -o $(NAME)

$(MLX)	:
	@$(MAKE) -c $(MLXDIR)

clean	:
	rm -rf $(OBJS)
	@$(MAKE) clean -C $(MLXDIR)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all fclean clean re
