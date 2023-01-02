/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:19:06 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/14 08:13:40 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef uint8_t	t_pflags;

typedef enum e_flagenum
{
	no_flags = 0,
	zero_padding = 1,
	right_padding = 2,
	space_padding = 4,
	alt_form = 8,
	plus_sign = 16,
	precision_flag = 32,
	nul_char = 64
}	t_flagenum;

typedef struct s_printfarg
{
	t_pflags	flags;
	size_t		width;
	size_t		precision;
}				t_printfarg;

int		ft_isflag(char c);
int		ft_isspec(char c);
int		ft_isargnum(char c);
int		ft_printf(const char *format, ...);

char	*ft_convert_ptr(uint64_t n);
char	*ft_itoa_base(uint64_t nb, char *base);
char	*ft_convert_hex(unsigned int n, int maj);
char	*ft_printf_create_buffer(size_t len, char c);
char	*ft_printf_int_pad(char *res, t_printfarg *args);
char	*ft_printf_str_pad(char *res, t_printfarg *args);
char	*ft_printf_bufferpad(size_t len, t_pflags flags);
char	*ft_printf_parsenum(char c, va_list ap, t_printfarg *args);
char	*ft_printf_parsespec(char c, va_list ap, t_printfarg *args);

size_t	ft_printf_parsearg(const char *format, va_list ap);
size_t	ft_printf_printarg(char c, va_list ap, t_printfarg *args);

#endif
