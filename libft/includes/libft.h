/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:23:05 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 11:49:27 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
/*	save a copy(of n length) of a string */
char				*ft_strndup(const char *s1, size_t n);
/*	 write zeroes to a byte string */
void				ft_bzero(void *s, size_t n);
/*	fill a byte string with a byte value */
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
/*	Calculate length of the string */
size_t				ft_strlen(const char *s);
/*	save a copy of a string */
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
/*	concatenate strings */
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
/*	locate character in string */
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
/*	locate a substring in a string */
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
/*	compare strings */
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*	convert ASCII string to integer */
int					ft_atoi(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*	Outputs the character c to the standard output. */
void				ft_putchar(char c);
/*	Outputs the string s to the standard output. */
void				ft_putstr(char const *s);
/*  Outputs the char c to the file descriptor fd. */
void				ft_putchar_fd(char c, int fd);
/*	Outputs the string s to the file descriptor fd. */
void				ft_putstr_fd(char const *s, int fd);
/*	Outputs the integer n to the standard output. */
void				ft_putnbr(int n);
/*	Outputs the integer n to the file descriptor fd. */
void				ft_putnbr_fd(int n, int fd);
/*	Outputs the string s to the standard output followed by a
 *	’\n’. */
void				ft_putendl(char const *s);
/*	Outputs the string s to the file descriptor fd followed by a
 *	’\n’ */
void				ft_putendl_fd(char const *s, int fd);
/*	Sets every character of the string to the value ’\0’ */
void				ft_strclr(char *s);
/*	Takes as a parameter the address of a string that need to be
 *	freed with free(3), then sets its pointer to NULL. */
void				ft_strdel(char **as);
/*	Allocates (with malloc(3)) and returns a “fresh” memory
 *	area. The memory allocated is initialized to 0. If the allocation
 *	fails, the function returns NULL. */
void				*ft_memalloc(size_t size);
/*	Takes as a parameter the address of a memory area that needs
 *	to be freed with free(3), then puts the pointer to NULL */
void				ft_memdel(void **ap);
/*	Allocates (with malloc(3)) and returns a “fresh” string ending
 *	with ’\0’. Each character of the string is initialized at
 *	’\0’. If the allocation fails the function returns NULL. */
char				*ft_strnew(size_t size);
/*	Applies the function f to each character of the string passed
 *	as argument. Each character is passed by address to f to be
 *	modified if necessary. */
void				ft_striter(char *s, void (*f)(char *));
/*	Applies the function f to each character of the string passed
 *	as argument, and passing its index as first argument. Each
 *	character is passed by address to f to be modified if necessary. */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*	Applies the function f to each character of the string given
 *	as argument to create a “fresh” new string (with malloc(3))
 *	resulting from the successive applications of f. */
char				*ft_strmap(char const *s, char (*f)(char));
/*	Applies the function f to each character of the string passed
 *	as argument by giving its index as first argument to create a
 *	“fresh” new string (with malloc(3)) resulting from the successive
 *	applications of f. */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*	Lexicographical comparison between s1 and s2. If the 2
 *	strings are identical the function returns 1, or 0 otherwise. */
int					ft_strequ(char const *s1, char const *s2);
/*	Lexicographical comparison between s1 and s2 up to n characters
 *	or until a ’\0’ is reached. If the 2 strings are identical,
 *	the function returns 1, or 0 otherwise. */
int					ft_strnequ(char const *s1, char const *s2, size_t n);
/*	Allocates (with malloc(3)) and returns a “fresh” substring
 *	from the string given as argument. The substring begins at
 *	indexstart and is of size len. If start and len aren’t refering
 *	to a valid substring, the behavior is undefined. If the
 *	allocation fails, the function returns NULL. */
char				*ft_strsub(char const *s, unsigned int start, size_t len);
/*	Allocates (with malloc(3)) and returns a “fresh” string ending
 *	with ’\0’, result of the concatenation of s1 and s2. If
 *	the allocation fails the function returns NULL. */
char				*ft_strjoin(char const *s1, char const *s2);
/*	Allocates (with malloc(3)) and returns a copy of the string
 *	given as argument without whitespaces at the beginning or at
 *	the end of the string. Will be considered as whitespaces the
 *	following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces
 *	at the beginning or at the end, the function returns a
 *	copy of s. If the allocation fails the function returns NULL. */
char				*ft_strtrim(char const *s);
/*	Allocate (with malloc(3)) and returns a “fresh” string ending
 *	with ’\0’ representing the integer n given as argument.
 *	Negative numbers must be supported. If the allocation fails,
 *	the function returns NULL. */
char				*ft_itoa(int n);
/*	Allocates (with malloc(3)) and returns an array of “fresh”
 *	strings (all ending with ’\0’, including the array itself) obtained
 *	by spliting s using the character c as a delimiter.
 *	If the allocation fails the function returns NULL. Example
 *	: ft_strsplit("*hello*fellow***students*", ’*’) returns
 *	the array ["hello", "fellow", "students"]. */
char				**ft_strsplit(char const *s, char c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_str_case(char *s, int up_or_low);
char				*ft_strapnd(char *s, char c);
/*	Print two strings on stdout.
*/
void				ft_putstrstr(char *s1, char *s2);
void				ft_foreach(char const *s, void (*f)(char));
/*	NEW;
 *	0 - Success, 1 - Error.
 */
int					ft_strdchar(char **s, int pos);
int					ft_strichar(char **s, int pos, char c);
/*	Return last char of the given string.
*/
char				ft_lastchar(char *s);


/*
**	return a new reversed copy of s.
*/
char				*ft_strrev(const char *s);
/*
**	Refer to file for description.
*/
int					ft_strrevcmp(const char *s1, const char *s2);
int					ft_strrevncmp(const char *s1, const char *s2, size_t n);
/*	deletes s and return new copy with c aappended to it.
*/
char				*ft_straddch(char *s, char c);
#endif
