/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:40:59 by aiturria          #+#    #+#             */
/*   Updated: 2024/06/24 15:26:09 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//check if it is a letter
int		ft_isalpha(int c);
//check if it is a number
int		ft_isdigit(int c);
//check if it is alphanumeric character
int		ft_isalnum(int c);
//check if is an ascii character
int		ft_isascii(int c);
//check if it is a printable character
int		ft_isprint(int c);
//count characters in the string
int		ft_strlen(const char *str);
//print c in string until n characters
void	*ft_memset(void *dest, int c, size_t n);
//put n zeros to string leaving the rest 
void	ft_bzero(void *str, size_t n);
//copy src to dest until n characters leaving the rest
void	*ft_memcpy(void *dest, const void *src, size_t n);
//same memcopy but safer when overlaping
void	*ft_memmove(void *dest, const void *src, size_t n);
//copy n src characters into dest erasing the rest
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
//concatenate strings until size and returns intended size
size_t	ft_strlcat(char *dest, const char *src, size_t size);
//converts lower case letters to upper case
int		ft_toupper(int c);
//converts upper case letters to lower case
int		ft_tolower(int c);
//looks for first occurence of c in the string
char	*ft_strchr(const char *s, int c);
//looks for last ocurrence of c in the string
char	*ft_strrchr(const char *s, int c);
//look for diff returning ascii diff value
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//looks for c in the string until n characters
void	*ft_memchr(const void *s, int c, size_t n);
//looks for diff until n characters returning ascii diff
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//looks for whole needle ocurrence until size
char	*ft_strnstr(const char *haystack, const char *needle, size_t size);
//coverts initial number string to int
int		ft_atoi(const char *str);
//reserve contiguous memory space
void	*ft_calloc(size_t count, size_t size);
//reserve space and copy the string into new one;
char	*ft_strdup(const char *s1);
//copy part of the str to a new one
char	*ft_substr(const char *s, unsigned int start, size_t len);
//concatenate two strings into a new one
char	*ft_strjoin(char const *s1, char const *s2);
//trim set characters from beginning and end of string
char	*ft_strtrim(char const *s1, char const *set);
//separate a string in substrings without including c
char	**ft_split(char const *s, char c);
//convert an int into a string
char	*ft_itoa(int n);
//apply a function to every char in the string returning a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//apply a function to every char returning nothing
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//write a character into a file descriptor
void	ft_putchar_fd(char c, int fd);
//write a string into a file descriptor
void	ft_putstr_fd(char *s, int fd);
//write a string into a fd and add a line feed 
void	ft_putendl_fd(char *s, int fd);
//write a number into a file descriptor
void	ft_putnbr_fd(int n, int fd);

//create new node, the only one so pointing to null
t_list	*ft_lstnew(void *content);
//insert new node at the beggining of list
void	ft_lstadd_front(t_list **lst, t_list *new);
//count the number of nodes in a list
int		ft_lstsize(t_list *lst);
//return pointing to the last node
t_list	*ft_lstlast(t_list *lst);
//add a node at the end of list
void	ft_lstadd_back(t_list **lst, t_list *new);
//delete the node lst with the function del
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//clear the contents of the node and thereafter
void	ft_lstclear(t_list **lst, void (*del)(void *));
//apply funtion to the nodes of the list
void	ft_lstiter(t_list *lst, void (*f)(void *));
//apply a function and create a new list with them
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//ft_printf for c, s, d. i, p, x, X, %
int		ft_printf(const char *format, ...);
int		ft_specifier(va_list args, char format);
int		ft_putcharr(int format);
int		ft_putstring(char *format);
int		ft_putint(int n);
int		ft_putunsigint(unsigned int n);
int		ft_putpointer(uintptr_t pointer);
int		ft_puthexadem(unsigned int pointer, char letter);

//get next line
char	*get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*ft_gnlstrchr(char *s, int c);
int		ft_gnlstrlen(char *str);

#endif /*LIBFT_H*/
