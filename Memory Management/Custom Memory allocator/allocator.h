#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>  // For size_t

struct BLOCK {
    size_t size;
    struct BLOCK *next;
    int free;
};

// Declare `head` as an external variable so it can be used across files
extern struct BLOCK *head;

void *my_malloc(size_t size);
void my_free(void *ptr);
struct BLOCK *find_free_Block(size_t size);
struct BLOCK *requestMemory(size_t size);

#endif // ALLOCATOR_H
