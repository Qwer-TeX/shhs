#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/blake2.h>
#include "hash.h"

void calculate_blake2(const char *filename) {
    unsigned char hash[BLAKE2B_DIGEST_LENGTH]; // Change to BLAKE2S_DIGEST_LENGTH for BLAKE2s
    BLAKE2b_CTX blake2_ctx; // Use BLAKE2s_CTX for BLAKE2s
    BLAKE2b_Init(&blake2_ctx); // Use BLAKE2s_Init for BLAKE2s

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        BLAKE2b_Update(&blake2_ctx, buffer, bytesRead); // Use BLAKE2s_Update for BLAKE2s
    }
    BLAKE2b_Final(hash, &blake2_ctx); // Use BLAKE2s_Final for BLAKE2s
    fclose(file);

    printf("BLAKE2b: ");
    for (int i = 0; i < BLAKE2B_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
