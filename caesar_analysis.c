//(str[i] - 'a' + key) % 26 + 'a'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_LETTERS 10

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

int* count_frequencies(char* cipher){
    int* frequencies = (int*) malloc(sizeof(int)* ALPHA_LENGTH);
    memset(frequencies, 0, sizeof(int) * ALPHA_LENGTH);
    int length = strlen(cipher);
    for(int i = 0; i < length; i++){
        char symbol = tolower(cipher[i]);
        if(symbol >= 'a' && symbol <='z'){
            int position = symbol - 'a';
            frequencies[position]++;
        }
    }
    return frequencies;
}

int get_max_index(int* frequencies){
    int max_index = 0;
    for(int i = 0; i <ALPHA_LENGTH; i++){
        if(frequencies[i] > frequencies[max_index]){
            max_index = i;
        }
    }
    return max_index;
}

int main(){
    char cipher[MAXN];
    read_cipher("cipher.txt", cipher);
    int* frequencies = count_frequencies(cipher);
    char letter = get_max_index(frequencies) + 'a';
    char commons[COMMON_LETTERS] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'l'};
    for (int i = 0; i < COMMON_LETTERS; i++){
        int key = abs(letter - commons[i]);
        char* text = cezar_decipher(cipher, key);
        printf("Key=%d, cipher ->%s\n", key, text);
        free(text);
    }
    return 0;
}