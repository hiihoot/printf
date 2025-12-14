/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hihoot <hihoot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:10:00 by hihoot            #+#    #+#             */
/*   Updated: 2025/12/13 22:10:00 by hihoot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(int c)
{
	return (write(1, &c, 1));
}

int	put_str(const char *s)
{
	int	count;

	count = 0;
	if(!s)
	{
		count += put_str("(null)");
		return (count);
	}

	while (*s)
	{
		count += put_char(*s);
		s++;
	}
	return (count);
}

int	put_number(long n, int base)
{
	int		count;
	char	*b;

	count = 0;
	b = "0123456789abcdef";
	if (n < 0)
	{
		put_char('-');
		n = -n;
		count++;
	}
	if (n >= base)
		count += put_number(n / base, base);
	count += put_char(b[n % base]);
	return (count);
}

int	put_number_cap(long n, int base)
{
	int		count;
	char	*b;

	count = 0;
	b = "0123456789ABCDEF";
	if (n < 0)
	{
		count += put_char('-');
		n = -n;
	}
	if (n >= base)
		count += put_number_cap(n / base, base);
	count += put_char(b[n % base]);
	return (count);
}
