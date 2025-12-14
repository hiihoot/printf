/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hihoot <hihoot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:30:00 by hihoot            #+#    #+#             */
/*   Updated: 2025/12/13 23:30:00 by hihoot           ###   ########.fr       */
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