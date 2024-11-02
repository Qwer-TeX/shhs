#ifndef HASH_H
#define HASH_H

void calculate_md5(const char *filename);
void calculate_sha1(const char *filename);
void calculate_sha256(const char *filename);
void calculate_sha512(const char *filename);

#endif // HASH_H
