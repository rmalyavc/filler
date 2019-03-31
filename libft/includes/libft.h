/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:07:23 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/16 21:39:27 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnllst
{
	char			*flow;
	int				rd;
	int				fd;
}					t_gnllst;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, char *src);
int					ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src,
					size_t dstsize);
size_t				ft_strlen(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2,
					size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_strsplit_lst(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_count_strings(char **buffer);
void				ft_print_buff(char **buffer);
size_t				ft_file_size(int fd);
int					ft_clean_buff(char	**buffer, char ***ptr);
void				ft_clean_matrix(char ***matrix, char ****ptr);
void				ft_swap_ch(char **s1, char **s2);
char				**ft_create_buff(size_t size, size_t len);
void				ft_swap_buff(char ***b1, char ***b2);
int					ft_factorial(int nb);
char				**ft_buff_cpy(char **buffer);
char				*ft_itoa_base(intmax_t nb, int base, int flag);
char				*ft_utoa_base(uintmax_t nb, int base, int flag);
char				*ft_str_low(char *str);
char				*ft_str_up(char *str);
int					ft_str_search(char **haystack, char *needle);
char				**ft_str_push(char **buffer, char *str);
int					ft_strchr_n(char *str, char c);
int					ft_atoi_base(const char *str, int base);
char				*ft_str_merge(char *dst, char *s1, char *s2);
unsigned char		*ft_unicode(int arr[]);
size_t				ft_unilen(unsigned char *str);
char				*ft_ftoa(long double nb, int prec);
char				*ft_fetoa(long double nb, int prec);
intmax_t			ft_power(int nb, int power);
void				ft_merge_sort(long long int *tab, int n);
long long int		ft_atoll(const char *str);
void				ft_lstpush(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst);
int					isnum(char *str);
void				ft_lstprint(t_list *lst);
size_t				ft_lstlen(t_list *lst);
int					ft_abs(int value);
int					open_file(char *file);
t_list				*file_to_lst(int fd);
char				**ft_lst_to_buff(t_list **lst, int clean);
int					ft_strchr_arr(char *haystack, char *needles);
char				*ft_strconcat(char *a, char *b);

#endif
