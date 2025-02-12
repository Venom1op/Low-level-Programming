#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OBJECT_SIZE 64
#define OBJECTS_PER_SLAB 8

// Structure to represent a slab
typedef struct Slab {
    void* objects[OBJECTS_PER_SLAB];  // Array of object pointers
    bool free_slots[OBJECTS_PER_SLAB]; // Tracks free or used objects
    struct Slab* next;
} Slab;

// Structure for managing slab cache
typedef struct SlabCache {
    Slab *head;
} SlabCache;

// Function to create a new slab
Slab *create_slab() {
    Slab *slab = (Slab*)malloc(sizeof(Slab));
    if (!slab) return NULL;

    for (int i = 0; i < OBJECTS_PER_SLAB; i++) {
        slab->objects[i] = malloc(OBJECT_SIZE);
        if (!slab->objects[i]) { // Handle allocation failure
            for (int j = 0; j < i; j++) {
                free(slab->objects[j]); 
            }
            free(slab);
            return NULL;
        }
        slab->free_slots[i] = true;
    }
    slab->next = NULL;
    return slab;
}

// Initialize slab cache
void init_slab_cache(SlabCache* cache) {
    cache->head = create_slab();
}

// Function to allocate an object from slab
void *slab_allocate(SlabCache *cache) {
    Slab *slab = cache->head;
    while (slab) {
        for (int i = 0; i < OBJECTS_PER_SLAB; i++) {
            if (slab->free_slots[i]) { 
                slab->free_slots[i] = false; // Mark as used
                return slab->objects[i];
            }
        }
        if (!slab->next) {
            slab->next = create_slab();
            if (!slab->next) return NULL; // Handle allocation failure
        }
        slab = slab->next;
    }
    return NULL;
}

// Function to free an object back to the slab
void slab_free(SlabCache *cache, void *ptr) {
    Slab *slab = cache->head;
    while (slab) {
        for (int i = 0; i < OBJECTS_PER_SLAB; i++) {
            if (slab->objects[i] == ptr) { 
                slab->free_slots[i] = true; // Mark slot as free
                return;
            }
        }
        slab = slab->next;
    }
}

// Free all allocated memory in slab cache
void destroy_slab_cache(SlabCache *cache) {
    Slab *slab = cache->head;
    while (slab) {
        Slab *next = slab->next;
        for (int i = 0; i < OBJECTS_PER_SLAB; i++) {
            free(slab->objects[i]);
        }
        free(slab);
        slab = next;
    }
}

// Main function to test slab allocator
int main() {
    SlabCache cache;
    init_slab_cache(&cache);

    void *ptr1 = slab_allocate(&cache);
    void *ptr2 = slab_allocate(&cache);

    printf("Allocated objects: %p and %p\n", ptr1, ptr2);

    slab_free(&cache, ptr1);
    slab_free(&cache, ptr2);

    destroy_slab_cache(&cache);
    return 0;
}
