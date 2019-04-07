FILLER = rmalyavc.filler
LIB = libft.a

all: $(LIB) $(FILLER)

$(LIB):
	@make re -C libft

$(FILLER): $(LIB)
	@gcc -Wall -Werror -Wextra main.c read.c init.c paste_figure.c ./libft/libft.a -o $(FILLER) -I ./bin/ -I ./libft/includes
	@echo "\033[32mrmalyavc.filler is compiled\033[0m"

clean:
	@make clean -C libft

fclean:
	@make fclean -C libft
	@/bin/rm -f $(FILLER)
	@echo "\033[31mrmalyavc.filler has been removed\033[0m"

re: fclean all