
#include "ft_printf.h"
#include <stdio.h>



int main()
{
	// ft_printf("%%%%%");
    // printf("\n============================\n");
    // printf("%%%%%");

    int a = ft_printf("%%%%");
    // int b = printf("%%%%%");
    printf("%d",a);
    printf("\n============================\n");
    int b = printf("%%%%");
    printf("%d",b);


    // printf("%d",b);

    return 0;

}