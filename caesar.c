//(str[i] - 'a' + key) % 26 + 'a'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            str[i] = (cipher[i] - '0' - key + 10) % 10 + '9';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    str[length] = '\0';

    return str;
}

char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (cipher[i] - 'a' + key ) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (cipher[i] - 'A' + key ) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            str[i] = (cipher[i] - '0' + key )  % 10 + '9';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    cipher[length] = '\0';
    return cipher;
}


int read_cipher(char* filename, char* cipher)
{
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        fp = fopen(filename, "w");
        printf("Created a text file due to the lack of one\n");
        return 1;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.\n");
        return 1;
    }

    fclose(fp);

    return 0;
}


int main()
{
    int choice;
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    char cipher[MAXN];
    printf("\nCipher-1 \nDecipher-0\nEND-2\n\n");
    scanf("%d", &choice);
    switch(choice){
        case 0:
    if(read_cipher(filename, cipher) == 0)
    {
        FILE* fp;
        int key;
        printf("Enter key:\n");
        scanf("%d", &key);
    
        char* text = cezar_decipher(cipher, key);

        printf("%s", text);
        fp = fopen("plaintext.txt", "w");
        fprintf(fp, "%s", text);
        fclose(fp);
        free(text);

        

        return 0;    
    }
    else
    {
        return 1;
    }
    break;
        case 1:
        char str[MAXN];
    scanf("%s", str);
    int key;
    scanf("%d", &key);
    char* cipher = cezar_cipher(str, key);
    printf("%s", cipher);
    return 0;
    break;
        case 2:
        exit(0);
        break;
    default: 
        printf("Invalid choice. You suck.");
        return 1;
    }
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_cipher(char* str, int key){
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char)*(length+1));
    for(int i=0; i<length; i++){
        cipher[i]=(str[i]- 'a' + key) % 26 + 'a';
    }
    cipher[length]='\0';
    return cipher;
}

int main(){
    char str[MAXN];
    scanf("%s", str);
    int key;
    scanf("%d", &key);

    char* cipher= cezar_cipher(str, key);
    printf("%s", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}
