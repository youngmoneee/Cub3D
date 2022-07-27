NAME	= cub3d
CC		= cc
CFLAGS	= #-Wall -Wextra -Werror

#FRMWRK	= -framework Opengl -framework Appkit
FRMWRK = -framework Metal -framework Metalkit
MLX		= mlx
MLXDIR	= mlxdir
LIBFT	= ft
LIBDIR	= libft

INC		= inc

SRCD	= src
SRCF	= main.c \
		  parse_1.c \
		  parse_detail.c \
		  basic_util.c

SRCS	= $(addprefix $(SRCD)/, $(SRCF))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

all	:	$(NAME)

$(NAME)	: $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -I $(INC) -L. -l$(MLX) -l$(LIBFT) $(FRMWRK) -o $(NAME)

$(MLX)	:
	@$(MAKE) -C $(MLXDIR)
	cp $(MLXDIR)/libmlx.dylib ./

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/libft.a ./

clean	:
	rm -rf $(OBJS)
	#@$(MAKE) clean -C $(MLXDIR)
	#@$(MAKE) clean -C $(LIBDIR)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all fclean clean re
