#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start (ap, format);
	while (*(format) != '\0')
	{
		if (*format == '%' && *(format + 1) == '%')
			count += write (1, format++, 1);
		else if (*format == '%')
			count += print_format (*(++format), ap);
		else
			count += write (1, format, 1);
		format++;
	}
	va_end (ap);
	return (count);
}