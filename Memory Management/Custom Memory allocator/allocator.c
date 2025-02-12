#include "allocator.h"
#include <unistd.h>
#include <stdio.h>

 struct BLOCK *head = NULL; // Head of the linked list

// Function to find a free block in memory
struct BLOCK *find_free_Block(size_t size) {
    if (!head) return NULL;
    
    struct BLOCK *current = head;
    do {
        if (current->free && current->size >= size) {
            return current;
        }
        current = current->next;
    } while (current != head);
    
    return NULL;
}

// Custom malloc implementation
void *my_malloc(size_t size) {
    if (size <= 0) return NULL;

    struct BLOCK *block = find_free_Block(size);

    if (!block) {
        block = requestMemory(size);
        if (!block) return NULL; // Failed to allocate memory
    } else {
        block->free = 0;  // Mark block as used
    }

    return (void *)(block + 1);
}

// Custom free implementation
void my_free(void *ptr) {
    if (!ptr) return;

    struct BLOCK *block = (struct BLOCK *)ptr - 1;
    block->free = 1;  // Mark block as free
}
