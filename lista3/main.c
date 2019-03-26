#include <stdio.h>
#include <stdlib.h>
#include "aleatorio.h"

#define IN_FILE_NAME "./cifra_xor_b.txt"
#define OUT_FILE_NAME "./decifrado_xor_b.txt"

char cifra(char key, char c);

int main()
{
    /*
    int i;
    for (i = 0; i < 10; i++) {
        printf("Posicao: %d, numero aleatorio: %d\n", i, aleatorio());
    }
    */
    int i;
    char c, c_d;
    unsigned long long int k;
    FILE* inFile = fopen(IN_FILE_NAME, "r");
    FILE* outFile = fopen(OUT_FILE_NAME, "w");
    
    if(inFile == NULL || outFile == NULL)
        return -1;
    
    k = aleatorio() % 26;

    while(!feof(inFile))
    {
        fscanf(inFile, "%c", &c);
        char c_p;        

        if(c == ' ')
            c_p = c;
        else if (c == '\n')
            c_p = c;
        else
        {
            c -= 'a';
            c_d = cifra(c, k) % 26;
            c_p = c_d + 'a';
            
            semente(c);
            k = aleatorio() % 26;
        }

        fwrite(&(c_p), 1, sizeof(char), outFile);
        printf("%c", c_p);
    }    
    
    fclose(inFile);
    fclose(outFile);
    
    return 0;
}


char cifra(char key, char c)
{
    return (key^c);
}
