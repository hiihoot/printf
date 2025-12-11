#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//• %c Prints a single character.
int put_char(int c)
{
    return (write(1, &c, 1));
}
//• %s Prints a string
int put_str(const char *s)
{
    int count;

    count = 0;
    while (*s)
    {
        count += put_char(*s);
        s++;
    }
    return (count);
}
//• %d Prints a decimal (base 10) number.


//• %i Prints an integer in base 10

int     ft_printf(const char* f, ...)
{
    int count;

    va_list g;
    va_start(g, f);

    count = 0;
    while (*f)
    {
        if (*f == '%')
        {
            f++;
            if (*f == '%')
                count += write(1, f, 1);
            else if (*f == 'c')
                count += put_char(va_arg(g, int));
            else if (*f == 's')
                count += put_str(va_arg(g, char *));
            
        }
        f++;
    }

    printf("%d\n", count);

    va_end(g);
}

int main()
{
    ft_printf("%% %c %s", 'd', "salah how are you?");
    //printf("%% %s", "Salah how are you?");
}