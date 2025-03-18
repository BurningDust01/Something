#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt(char* plaintext, char* key){
    int text_length = strlen(plaintext);
    int key_length = strlen(key);
    char* cipher = (char*) malloc(sizeof(char)*text_length+1);
    memset (cipher, '\0', sizeof(char) * text_length + 1);
    for (int i = 0; i <text_length; i++){
        if(isalpha(plaintext[i])){
            int shift = tolower(key[i%key_length]) - 'a';
            if(islower(plaintext[i])){
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            }
            else{
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            }
        }
        else{
            cipher[i] = plaintext[i];
        }
    }
    cipher[text_length] = '\0';
    return cipher;
}

int read_text(char* filename, char* text){
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        fp = fopen(filename, "w");
        printf("Created a text file due to the lack of one\n");
        return 1;
    }

    if(fgets(text, MAXN, fp) == NULL)
    {
        printf("Error reading from file.\n");
        return 1;
    }

    fclose(fp);

    return 0;
}

int read_key (char* filename, char* key){
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        fp = fopen(filename, "w");
        printf("Created a text file due to the lack of one\n");
        return 1;
    }

    if(fgets(key, MAXN, fp) == NULL)
    {
        printf("Error reading from file.\n");
        return 1;
    }

    fclose(fp);

    return 0;
}

int main(){
    char text[MAXN];
    char filenameT[MAXN];
    char filenameK[MAXN];
    printf("Enter text filename: \n");
    scanf("%s", filenameT);
    printf("Enter key filename: \n");
    scanf("%s", filenameK);
    read_text(filenameT, text);
    char key[MAXN];
    read_key(filenameK, key);

    if(read_text(filenameT, text) == 0 && read_key(filenameK, key) == 0){
        FILE* fp;
        char* cipher = vigenere_encrypt(text, key);
        printf("%s", cipher);
        fp = fopen("vigenere_cipher.txt", "w");
        fprintf(fp, "%s", cipher);
        fclose(fp);
        free(cipher);
    }
    return 0;
}