# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 12:19:34 by rmalyavc          #+#    #+#              #
#    Updated: 2019/03/16 21:40:02 by rmalyavc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIST_C = ft_strconcat.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strsplit_lst.c ft_print_buff.c ft_count_strings.c ft_file_size.c ft_clean_buff.c ft_clean_matrix.c ft_swap_ch.c ft_create_buff.c ft_swap_buff.c ft_factorial.c ft_buff_cpy.c ft_itoa_base.c ft_str_low.c ft_str_up.c ft_str_search.c ft_str_push.c ft_strchr_n.c ft_atoi_base.c ft_str_merge.c ft_unicode.c ft_utoa_base.c ft_unilen.c ft_ftoa.c ft_power.c ft_fetoa.c ft_merge_sort.c get_next_line.c ft_atoll.c ft_lstpush.c ft_lstclear.c ft_lstprint.c ft_lstlen.c ./ft_printf/make_list.c ./ft_printf/push_data.c ./ft_printf/put_arg.c ./ft_printf/ft_printf.c ./ft_printf/conversions.c isnum.c ft_abs.c open_file.c file_to_lst.c ft_lst_to_buff.c ft_strchr_arr.c
LIST_O = ft_strconcat.o ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_strsplit_lst.o ft_print_buff.o ft_count_strings.o ft_file_size.o ft_clean_buff.o ft_clean_matrix.o ft_swap_ch.o ft_create_buff.o ft_swap_buff.o ft_factorial.o ft_buff_cpy.o ft_itoa_base.o ft_str_low.o ft_str_up.o ft_str_search.o ft_str_push.o ft_strchr_n.o ft_atoi_base.o ft_str_merge.o ft_unicode.o ft_utoa_base.o ft_unilen.o ft_ftoa.o ft_power.o ft_fetoa.o ft_merge_sort.o get_next_line.o ft_atoll.o ft_lstpush.o ft_lstclear.o ft_lstprint.o ft_lstlen.o make_list.o push_data.o put_arg.o ft_printf.o conversions.o isnum.o ft_abs.o open_file.o file_to_lst.o ft_lst_to_buff.o ft_strchr_arr.o
NAME = libft.a

all: $(NAME)

$(NAME): 
		@gcc -Wall -Werror -Wextra -O2 -c $(LIST_C) -I ./includes/
		@ar rc $(NAME) $(LIST_O)
		@echo "\033[32mLibft is compiled\033[0m"

clean:
		@/bin/rm -f $(LIST_O)
		@echo "\033[31mObject files had been removed\033[0m"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[31mLibft had been removed\033[0m"

re: fclean all
