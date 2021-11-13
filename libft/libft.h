/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalilove <xalilove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:30:23 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/13 21:30:02 by xalilove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_lstiter(t_list *lst, void (*f)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	*ft_memcpy(void *dest, const void *source, size_t n);
void	*ft_memccpy(void *dest, const void *source, int c, size_t n);
void	*ft_memmove(void *dest, const void *source, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr (const char *str, int ch);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	ft_char(char c, char const *set);
char	*ft_itoa(int n);
int		ft_lstsize(t_list *lst);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_issp(char p);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_islow(int c);
int		ft_toupper(int c);
int		ft_issup(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

#endif
