#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "hash.h"

void calculate_sha1(const char *filename) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA_CTX sha1_ctx;
    SHA1_Init(&sha1_ctx);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        SHA1_Update(&sha1_ctx, buffer, bytesRead);
    }
    SHA1_Final(hash, &sha1_ctx);
    fclose(file);

    printf("SHA-1: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
