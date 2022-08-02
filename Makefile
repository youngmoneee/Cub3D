NAME	= cub3d
CC		= cc
CFLAGS	= #-Wall -Wextra -Werror

FRMWRK	= -framework Opengl -framework Appkit
#FRMWRK = -framework Metal -framework Metalkit
MLX		= mlx
MLXDIR	= mlxdir
LIBFT	= ft
LIBDIR	= libft

INC		= inc

SRCD	= src

MODEL	= parse_1.c \
			parse_map.c \
			parse_option.c
DISPLAY	= window_init.c
#CONTROL =
UTIL	= basic_util.c


SRCF	= main.c \
		  $(addprefix model/, $(MODEL)) \
		  $(addprefix view/, $(VIEW)) \
		  #$(addprefix control/, $(CONTROL))
		  $(addprefix util/, $(UTIL))
		  

SRCS	= $(addprefix $(SRCD)/, $(SRCF))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

all	:	$(NAME)

debug:	$(OBJS) $(LIBFT) $(MLX)
	$(CC) -g $(CFLAGS) $(OBJS) -I $(INC) -L. -l$(MLX) -l$(LIBFT) $(FRMWRK) -o $(NAME)

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
	@$(MAKE) clean -C $(MLXDIR)
	@$(MAKE) clean -C $(LIBDIR)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all fclean clean re
