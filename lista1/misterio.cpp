#include <stdio.h>
#include <stdlib.h>

#define IN_FILE_NAME "./carta.txt"
#define OUT_FILE_NAME "./carta_descrip.txt"

#define SHIFT 3
#define ALPHABET_SIZE 26

char decrypt_char(char c);


int main()
{
    /*
    char b = 'd';
    printf("%c decrypted is %c\n", b, decrypt_char(b));
    */    
    FILE* inFile = fopen(IN_FILE_NAME, "r");
    FILE* outFile = fopen(OUT_FILE_NAME, "w");
    
    if(inFile == NULL || outFile == NULL)
        return -1;
    
    while(!feof(inFile))
    {
        char c, c_decrypt;
        fscanf(inFile, "%c", &c);
        c_decrypt = decrypt_char(c);
        fwrite(&c_decrypt, 1, sizeof(char), outFile);
        printf("%c", c_decrypt);    
    }    
    
    fclose(inFile);
    fclose(outFile);

    return 1;
}

/*
    Decrypts char crypted by Caesar's cipher
*/
char decrypt_char(char c)
{
    int c_decr = 0;
    if(c >= 'a' && c <='z')
    {
        c_decr = (c - 'a' - SHIFT + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
    }
    else
        c_decr = c;
    return (char)c_decr;
}
