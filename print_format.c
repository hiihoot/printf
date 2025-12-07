#include "ft_printf.h"

int	print_format(char s, va_list ap)
{
	int	count;

	count = 0;
	switch (s)
	{
		case 'c': count += ft_putchar(va_arg(ap, int)); break;
		case 's': count += ft_putstring(va_arg(ap, char *)); break;
		case 'i':
		case 'd': count += ft_putnumber((long)va_arg(ap, int), 10); break;
		case 'u': count += ft_putunit_max(va_arg(ap, unsigned int), 10); break;
		case 'x': count += ft_putnumber(va_arg(ap, unsigned int), 16); break;
		case 'X': count += ft_putnumber_caps(va_arg(ap, unsigned int), 16); break;
		case 'p': count += ft_putpointer(va_arg(ap, void *)); break;
		default: count += write(1, &s, 1);
	}
	return (count);
}

int	main()
{
	ft_printf("%d", 123);
}