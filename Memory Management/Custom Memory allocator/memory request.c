#include "allocator.h"
#include <unistd.h>
#include <stdio.h>

extern struct BLOCK *head;

// Function to request memory from OS using `sbrk()`
struct BLOCK *requestMemory(size_t size) {
    struct BLOCK *block = sbrk(0);
    void *request = sbrk(size + sizeof(struct BLOCK));

    if (request == (void *)-1) {
        return NULL;  // Memory allocation failed
    }

    block->size = size;
    block->free = 0;

    if (!head) {
        head = block;
        block->next = head;  // Circular linked list
    } else {
        struct BLOCK *current = head;
       
    }
}