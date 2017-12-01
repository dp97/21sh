/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:10:17 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 15:08:18 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# define PAD_RIGHT		1
# define PLUS_SIGN		2
# define HH_FLAG		4
# define H_FLAG			8
# define LL_FLAG		16
# define L_FLAG			32
# define INTMAX_T		64
# define SIZE_T			128
# define ALT_FORM		256
# define SPACE_FLAG		512
# define MAX_PRINT		1024
# define ZERO_FLAG		2048
# define COMMA_FLAG		4096
# define STAR_FLAG      8192
# define L_FLOAT_FLAG	16384
# define ACTIVE_COLOR		1
# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m\0"
# define SHOW_SIGN		0x00010000
# define STRING_FLAG	0x00020000

typedef union			u_convert
{
	float				f;
	struct
	{
		unsigned int	mantisa		: 22;
		unsigned int	quit_nan	: 1;
		unsigned int	exponent	: 8;
		unsigned int	sign		: 1;
	}					parts;
}						t_convert;

int						ft_printf(const char *format, ...);
void					ft_itoa_base(char *buf, \
		unsigned long long value, unsigned int base, int up_low);
char					*number_to_char(unsigned long long value, \
		char c, int *width, int *flag);
char					*float_to_char(long double value, char c, \
		int *width, int *flag);
char					*ft_wide_string(wchar_t *s);
int						ft_wide_char(wint_t ch);
int						ft_prints(char **s, int flag, int width[2]);
int						ft_puts(char *s, int len);
int						ft_len(char *s);
int						ft_putc(char c);
char					*ft_str_case(char *s, int up_or_low);
int						dp_strcpy(char *dst, const char *src);
char					*dp_strndup(const char *s1, size_t n);
int						dp_check_color(const char *s, int *flag);
int						dp_strcmp(char *s1, char *s2, int n);
int						ft_flags_1(const char *format, int *flag, \
		int width[2], va_list args);
int						ft_modifiers(const char *format, int *flags);
int						handle_d_i(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_u(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_o(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_x_p(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_f(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_c(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_s(const char *format, va_list args, \
		int *flag, int width[2]);
int						handle_b(const char *format, va_list args, \
		int *flag, int width[2]);
void					handle_n(va_list args, int *flag, \
		int char_written);
void					convert_i(char *buf, int *flag, \
		unsigned long long value);
void					convert_u(char *buf, int *flag, \
		unsigned long long value);
void					convert_o(char *buf, int *flag, \
		unsigned long long value);
int						convert_x(char *buf, int *flag, \
		unsigned long long value, short up_low);
int						convert_p(char *buf, int *flag, \
		unsigned long long value, short up_low);
unsigned char			*ft_to_utf8(wchar_t c);
unsigned char			*to_utf8(wchar_t c);
#endif
