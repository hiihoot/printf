#include "ft_printf.h"

int	ft_putunit_max(unsigned long num, int base)
{
	char	*digits;
	char	buffer[50];
	int		i;
	int		count;

	digits = "0123456789abcdef";
	i = 49;
	count = 0;
	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = digits[num % base];
		num /= base;
	}
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	ft_putpointer(void *pointer)
{
	unsigned long long	address;
	int					count;

	count = 0;
	address = (unsigned long long) pointer;
	if (pointer == NULL)
		return (ft_putstring("(nil)"));
	count += ft_putstring("0x");
	count += ft_putunit_max(address, 16);
	return (count);
}
