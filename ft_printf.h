/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:45:04 by sait-mou          #+#    #+#             */
/*   Updated: 2025/12/14 16:45:08 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	put_char(int c);
int	put_number(long n, int base);
int	put_number_cap(long n, int base);
int	format_checker(const char *f, va_list ap);
int	put_unit(unsigned long num, int base);
int	put_pointer(void *pointer);
int	put_str(const char *str);

#endif