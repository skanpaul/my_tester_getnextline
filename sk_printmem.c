/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void sk_printmem(void *ptr, size_t size)
{
    size_t i;
    unsigned char *byte;
    //unsigned int address;

    byte = (unsigned char *)ptr;
    /* ------------------------------------------- */
    
    // address = byte & 0x0FF;
    printf("\nMEMORY FROM %p\n", byte);
    // i = 0;
    // printf("MEM ADDR|");
    // while (i < size)
    // {
    //     printf("%02x|", address + (unsigned int)i);
    //     i++;
    // }
    printf("\n");
   
    /* ------------------------------------------- */
    i = 0;
    printf("INDEX i |");
    while (i < size)
    {
        printf("%02zu|", i);
        i++;
    }
    printf("\n");
    /* ------------------------------------------- */
    i = 0;
    printf("HEXA    |");
    while (i < size)
    {
        printf("%02x|", byte[i]);
        i++;
    }
    printf("\n");
    /* ------------------------------------------- */
    i = 0;
    printf("CHAR    |");
    while (i < size)
    {
        if (isprint(byte[i]))
            printf(" %c|", byte[i]);
        else
            printf("__|");
        i++;
    }
    printf("\n");
    printf("\n");
}