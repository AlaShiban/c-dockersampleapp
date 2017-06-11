/* Fibonacci Series c language */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./murmur3/murmur3.c"

int main()
{
    unsigned long n, first = 0, second = 1, next, c;
    uint32_t hash;      /* Output for the hash */
    uint32_t seed = 42; /* Seed value for hash */

    FILE *pFile;
    pFile = fopen("output.txt", "a");
    n = 10;

    printf("First %ld terms of Fibonacci series are :-\n", n);
    char str[2048];
    for (c = 0; c < n; c++)
    {
        if (c <= 1)
            next = c;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        sprintf(str, "%ld", next);
        MurmurHash3_x86_32(str, strlen(str), seed, &hash);
        
        //printf("x86_32:  %08x\n", hash[0]);

        printf("Fib: %s --> Hash: %08x\n", str, hash);
        fprintf(pFile, "Fib: %s --> Hash: %08x\n", str, hash);
    }
    fclose(pFile);
    printf("\nCompleted!\n");
    return 0;
}