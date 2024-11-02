#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    calculate_md5(filename);
    calculate_sha1(filename);
    calculate_sha256(filename);
    calculate_sha512(filename);
    calculate_blake2(filename);

    return EXIT_SUCCESS;
}
