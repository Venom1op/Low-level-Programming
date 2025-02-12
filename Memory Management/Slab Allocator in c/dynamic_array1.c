#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OBJECT_SIZE 64 // bytes
#define OBJECTS_PER_SLAB 8

// Structure of the slab
typedef struct Slab {
  void *object[OBJECTS_PER_SLAB];
  bool free_slots[OBJECTS_PER_SLAB];
  struct Slab *next;
} Slab;

typedef struct SlabCache {
  Slab *head;
} SlabCache;

// Create a slab
Slab *create_slab() {
  Slab *slab = (Slab *)malloc(sizeof(Slab)); // Allocate memory for slab
  if (!slab)
    return NULL; // Failed to allocate memory for slab

  for (int i = 0; i < OBJECTS_PER_SLAB; i++) { // Allocate memory for each object
    slab->object[i] = malloc(OBJECT_SIZE);
    if (!slab->object[i]) {
      // Free previously allocated objects if allocation fails
      for (int j = 0; j < i; j++) {
        free(slab->object[j]);
      }
      free(slab);
      return NULL;
    }
    slab->free_slots[i] = true;
  }
  slab->next = NULL;
  return slab;
}

// Initialize the slab cache
void init_slab_cache(SlabCache *cache) {
  cache->head = create_slab();
  if (!cache->head) {
    printf("Failed to initialize slab cache\n");
  }
}
// Allocate an object from the slab
void *slab_allocate(SlabCache *cache) {
  Slab *slab = cache->head;

  while (slab) {
    for (int i = 0; i < OBJECTS_PER_SLAB; i++) {
      if (slab->free_slots[i]) {     // If slot is free
        slab->free_slots[i] = false; // Mark as used
        return slab->object[i];      // Return the object pointer
      }
    }

    // If no free slot, check the next slab
    if (!slab->next) {
      slab->next = create_slab(); // Create a new slab
      if (!slab->next) {
        return NULL; // Failed to create a new slab
      }
    }

    slab = slab->next; // Move to the next slab
  }

  return NULL; // Should never reach here
}

// Free an object in the slab
void slab_free(SlabCache *cache, void *object) {
  Slab *slab = cache->head;

  while (slab) {
    for (int i = 0; i < OBJECTS_PER_SLAB; i++) {
      if (slab->object[i] == object) {
        slab->free_slots[i] = true; // Mark as free
        return;
      }
    }
    slab = slab->next;
  }
}

// Dynamic array structure
typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} Dynamic_array;

// Initialize the dynamic array
void Dynamic_array_init(Dynamic_array *arr, SlabCache *cache) {
  arr->size = 0;
  arr->capacity = 4;
  arr->data = (int *)slab_allocate(cache);
  if (!arr->data) {
    printf("Failed to allocate memory for dynamic array\n");
    exit(1);
  }
}

// Insert a value into the dynamic array
void dynamic_array_insert(Dynamic_array *arr, SlabCache *cache, int value) {
  if (arr->size >= arr->capacity) {
    arr->capacity *= 2;
    void *new_memory = slab_allocate(cache);
    if (!new_memory) {
      printf("Failed to allocate memory for dynamic array resize\n");
      return;
    }
    memcpy(new_memory, arr->data, arr->size * sizeof(int));
    slab_free(cache, arr->data); // Free the old memory
    arr->data = (int *)new_memory;
  }
  // Insert the new data
  arr->data[arr->size] = value;
  arr->size++;
}

// Example usage
int main() {
  SlabCache cache;
  init_slab_cache(&cache);

  Dynamic_array arr;
  Dynamic_array_init(&arr, &cache);

  for (int i = 0; i < 10; i++) {
    dynamic_array_insert(&arr, &cache, 23+i);
  }

  for (size_t i = 0; i < arr.size; i++) {
    printf("%d ", arr.data[i]);
  }
  printf("\n");

  return 0;
}