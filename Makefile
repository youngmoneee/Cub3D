NAME	= cub3d
CC		= arch -x86_64 cc
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
			parse_option.c \
			parse_user.c \
			init.c
VIEW	= render.c \
			minimap.c \
			ray.c
CONTROL = move.c \
			key_handler.c
UTIL	= basic_util.c

SRCF	= main.c \
		  $(addprefix model/, $(MODEL)) \
		  $(addprefix view/, $(VIEW)) \
		  $(addprefix util/, $(UTIL)) \
		  $(addprefix control/, $(CONTROL))

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
	#@$(MAKE) clean -C $(MLXDIR)
	#@$(MAKE) clean -C $(LIBDIR)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all fclean clean re
