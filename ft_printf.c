/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-mou <sait-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:44:54 by sait-mou          #+#    #+#             */
/*   Updated: 2025/12/14 16:50:02 by sait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_checker(const char *f, va_list g)
{
	int	count;

	count = 0;
	if (*f == '%')
		count += write(1, f, 1);
	else if (*f == 'c')
		count += put_char(va_arg(g, int));
	else if (*f == 's')
		count += put_str(va_arg(g, char *));
	else if (*f == 'd' || *f == 'i')
		count += put_number(va_arg(g, int), 10);
	else if (*f == 'X')
		count += put_number_cap(va_arg(g, unsigned int), 16);
	else if (*f == 'x')
		count += put_number(va_arg(g, unsigned int), 16);
	else if (*f == 'p')
		count += put_pointer(va_arg(g, void *));
    else if (*f == 'u')
		count += put_number(va_arg(g, unsigned int), 10);
    else
		put_char(*f);
    return (count);
}

int	put_unit(unsigned long n, int base)
{
	int		count;
	char	buffer[50];
	int		i;
	char	*b;

	count = 0;
	i = 49;
	buffer[i] = '\0';
	b = "0123456789abcdef";
	if (n == 0)
		buffer[--i] = '0';
	while (n > 0)
	{
		buffer[--i] = b[n % base];
		n /= base;
	}
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	put_pointer(void *pointer)
{
	unsigned long long	address;
	int					count;

	if (!pointer)
		return (put_str("(nil)"));
	count = 0;
	address = (unsigned long long)pointer;
	count += put_str("0x");
	count += put_unit(address, 16);
	return (count);
}

int	ft_printf(const char *f, ...)
{
	int		count;
	va_list	g;

	count = 0;
	va_start(g, f);
	if (!f)
    	return (-1);
	while (*f)
	{
        if (*f == '%')
		{
			f++;
		    count += format_checker(f, g);
		} else
			count += write(1, f, 1);
		f++;
	}
	va_end(g);
	return (count);
}
