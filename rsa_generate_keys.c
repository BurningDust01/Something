#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

int main(){

    int bits = 2048;
    int result = 0;
    BIGNUM *big = BN_new();
    result = BN_set_word(big, RSA_F4);

    RSA *r = RSA_new();
    RSA_generate_key_ex(r, bits, big, NULL);
    BIO *bp_public = BIO_new_file("public.pem", "w+");
    PEM_write_bio_RSAPublicKey(bp_public, r);

    BIO *bp_private = BIO_new_file("private.pem", "w+");
    PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);
    printf("Done\n");
    return 0;

}