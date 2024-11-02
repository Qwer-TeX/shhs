#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "hash.h"

void calculate_sha512(const char *filename) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX sha512_ctx;
    SHA512_Init(&sha512_ctx);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        SHA512_Update(&sha512_ctx, buffer, bytesRead);
    }
    SHA512_Final(hash, &sha512_ctx);
    fclose(file);

    printf("SHA-512: ");
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
