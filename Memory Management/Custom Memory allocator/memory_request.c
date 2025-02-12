#include "allocator.h"
#include <unistd.h>
#include <stdio.h>

// Request memory from the OS using sbrk()
struct BLOCK *requestMemory(size_t size)
{
    struct BLOCK *block = sbrk(0); // Get the current program break
    void *request = sbrk(size + sizeof(struct BLOCK)); // Request memory

    if (request == (void *)-1)   
    {
        return NULL; // Memory request failed
    }

    block->size = size;    // Set the size of the block
    block->free = 0;       // Mark the block as used
    extern struct BLOCK *head;

    if (!head)
    {
        // First block, initialize the head
        head = block;
        block->next = head; // Circular link
    }
    else
    {
        // If there is already a block, add this one to the list
        struct BLOCK *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = block; // Attach new block to the list
        block->next = head;    // Complete the circular link
    }

    return block; // Return the block (without the header part, the memory starts just after the header)
}
