#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

#define MAXN 1000
#define KEY_SIZE 8

unsigned char hex_to_byte(unsigned char* hex){
    unsigned int byte;
    sscanf(hex, "%02x", &byte);
    return (unsigned char) byte;
}

int main(){
    unsigned char key[KEY_SIZE] = "banichka";
    char hex_input[MAXN * 2];
    scanf("%s", hex_input);
    int hex_len = strlen(hex_input);
    if(hex_len % 2 != 0){
        printf("Invalid hex number");
        return 1;
    }
    int chipher_len = hex_len / 2;
    unsigned char cipher[chipher_len];
    for(int i = 0; i < chipher_len; i++){
        cipher[i] = hex_to_byte(&hex_input[i*2]);
    }

    unsigned char decrypted[chipher_len];
    DES_key_schedule key_schedule;
    DES_set_key((DES_cblock*) key, &key_schedule);

    for(int i =0; i <chipher_len; i+=8){
        DES_ecb_encrypt ((DES_cblock*) (cipher +i),
        (DES_cblock*) (decrypted + i), &key_schedule, DES_DECRYPT);
    }

    unsigned char pad_value = decrypted[chipher_len - 1];
    if(pad_value > 8){
        pad_value = 0;
    }
    int original_len = chipher_len - pad_value;
    fwrite(decrypted, 1, original_len, stdout);
    printf("\n");
    return 0;
}