#include "hash.h"

#include <stdint.h>
#include <stdio.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME  2933985336779UL

uint64_t fnv_hash(const char* input)
{
    uint64_t hash = FNV_OFFSET;

    for(const char* i = input; *i; i++)
    {
        hash ^= (uint64_t)(unsigned char)(*i);
        hash *= FNV_PRIME;
    }

    return hash;
}

int main(int argc, char* argv[]) 
{
    if(argc != 2)
    {
        printf("Invalid input: requires exactly one string");
        return -1;
    }

    char* input = argv[1];
    uint64_t hash = fnv_hash(input);

    printf("%lu\n", hash);

    return 0;
}
