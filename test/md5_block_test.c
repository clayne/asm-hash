#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "md5.h"

extern void md5_process_block_asm (uint32_t* hash, uint8_t* block);

uint8_t block[] = {
	1, 2, 3, 4, 5, 6, 7, 8,
	9, 10, 11, 12, 13, 14, 15, 16,
	17, 18, 19, 20, 21, 22, 23, 24,
	25, 26, 27, 28, 29, 30, 31, 32,
	33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48,
	49, 50, 51, 52, 53, 54, 55, 56,
	57, 58, 59, 60, 61, 62, 63, 64
};

int main (void) {
	uint32_t hash_asm[4];
	uint32_t hash_ref[4];

	md5_process_block_asm (&hash_asm, &block);
	md5_process_block (&block, &hash_ref);

	printf ("%X %X %X %X\n", hash_asm[0], hash_asm[1], hash_asm[2], hash_asm[3]);
	printf ("%X %X %X %X\n", hash_ref[0], hash_ref[1], hash_ref[2], hash_ref[3]);
	if (hash_asm[0] == hash_ref[0] && hash_asm[1] == hash_ref[1] &&
		hash_asm[2] == hash_ref[2] && hash_asm[3] == hash_ref[3])
		printf ("identical\n");
	else
		printf ("different\n");

	return 0;
}