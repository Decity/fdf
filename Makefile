NAME			= fdf
CFLAGS			= -Wextra -Wall -Werror -Wunreachable-code -Og -g
LIBMLX			= ./libs/MLX42/
LIBFT			= ./libs/libft/
BUILD_DIR		= ./build/
SRC_DIR			= ./src/
HEADERS			= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS			= $(LIBMLX)/build/libmlx42.a $(LIBFT)/build/libft.a -ldl -lglfw -pthread -lm
SOURCE_FILES	= main.c init.c camera.c map.c limits.c points.c set_points.c set_projection.c transforms.c transforms_rotation.c colors.c draw.c hooks.c transform_hooks.c free.c utils.c
OBJECT_FILES	= $(SOURCE_FILES:%.c=$(BUILD_DIR)%.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)build && make -C $(LIBMLX)build -j4

libft:
	make -C $(LIBFT)

$(NAME): $(OBJECT_FILES)
	@$(CC) $(OBJECT_FILES) $(LIBS) $(HEADERS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@rm -rf $(OBJECT_FILES)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/build

re: fclean all

run: all
	$(NAME)

.PHONY: all clean fclean re run libmlx libft
