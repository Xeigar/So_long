NAME = libft.a

LIB_DIR = Libft/
PRT_DIR = ft_printf/
GET_DIR = get_next_line/

SRCS = $(GET_DIR)get_next_line.c $(GET_DIR)get_next_line_utils.c\
	$(PRT_DIR)ft_print_hex.c $(PRT_DIR)ft_print_Hex.c $(PRT_DIR)ft_print_usgn.c $(PRT_DIR)ft_print_void.c $(PRT_DIR)ft_print_void.c $(PRT_DIR)ft_printf.c $(PRT_DIR)ft_prints.c \
	$(LIB_DIR)ft_atoi.c $(LIB_DIR)ft_bzero.c $(LIB_DIR)ft_isalnum.c $(LIB_DIR)ft_isalpha.c $(LIB_DIR)ft_isascii.c $(LIB_DIR)ft_isdigit.c $(LIB_DIR)ft_memcmp.c $(LIB_DIR)ft_memcpy.c\
	$(LIB_DIR)ft_memmove.c $(LIB_DIR)ft_memset.c $(LIB_DIR)ft_isprint.c $(LIB_DIR)ft_strchr.c $(LIB_DIR)ft_strlcat.c $(LIB_DIR)ft_strlcpy.c $(LIB_DIR)ft_strlen.c $(LIB_DIR)ft_strncmp.c\
	$(LIB_DIR)ft_strnstr.c $(LIB_DIR)ft_strrchr.c $(LIB_DIR)ft_tolower.c $(LIB_DIR)ft_toupper.c $(LIB_DIR)ft_strdup.c $(LIB_DIR)ft_calloc.c $(LIB_DIR)ft_substr.c $(LIB_DIR)ft_strjoin.c\
	$(LIB_DIR)ft_strtrim.c $(LIB_DIR)ft_split.c $(LIB_DIR)ft_itoa.c $(LIB_DIR)ft_strmapi.c $(LIB_DIR)ft_striteri.c $(LIB_DIR)ft_putchar_fd.c $(LIB_DIR)ft_putstr_fd.c $(LIB_DIR)ft_putendl_fd.c\
	$(LIB_DIR)ft_putnbr_fd.c $(LIB_DIR)ft_memchr.c $(LIB_DIR)ft_lstnew.c $(LIB_DIR)ft_lstadd_front.c $(LIB_DIR)ft_lstsize.c $(LIB_DIR)ft_lstlast.c $(LIB_DIR)ft_lstadd_back.c\
	$(LIB_DIR)ft_lstdelone.c $(LIB_DIR)ft_lstclear.c $(LIB_DIR)ft_lstiter.c $(LIB_DIR)ft_lstmap.c
	

OBJT = ${SRCS:c=o}
CC = cc -Wall -Werror -Wextra -I .
MAKE = make -C

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJT)
	@echo "Combining get_next_line.a, libft.a and libprintf.a"
	ar rcs $(NAME) $(OBJT)

all: $(NAME)

clean:
	@echo "Deleting object files"
	@rm -rf $(OBJT)

fclean: clean
	@echo "Deleting libft.a"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
