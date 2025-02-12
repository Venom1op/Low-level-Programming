<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 13

// Person structure definition
typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person* next;
} person;

// Hash table array
person* hash_table[TABLE_SIZE];

// Hash function
unsigned int hash(char* name) {
    int len = strnlen(name, MAX_NAME);
    unsigned int prime = 7;
    unsigned int hash_value = 0;
    
    for (int i = 0; i < len; i++) {
        hash_value = hash_value * prime + name[i];
    }
    hash_value = hash_value % TABLE_SIZE; // Ensure it fits in the hash table size
    return hash_value;
}

// Insert function for hash table
bool insert(person* p) {
    if (p == NULL) return false;
    unsigned int index = hash(p->name);
    p->next = hash_table[index]; // Point the new person to the current first element at this index
    hash_table[index] = p;       // Update the hash table to point to the new person
    return true;
}
// Lookup function to find a person in the hash table
person* lookup(char* name) {
    unsigned int index = hash(name);
    person* temp = hash_table[index];
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp; // Person found
        temp = temp->next; // Move to the next person in the chain
    }   
    return NULL; // Person not found
}
// Initialize the hash table to NULL
void init_hashtable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

int main() {
    init_hashtable(); // Initialize the hash table
    
    // Creating person instances
    person anshul = {.name = "anshul", .age = 25, .next = NULL};
    person venom = {.name = "venom", .age = 18, .next = NULL};
    person rohit = {.name = "rohit", .age = 19, .next = NULL};
    
    // Inserting persons into the hash table
    insert(&anshul);
    insert(&venom);
    insert(&rohit);

    // Display the hash values for each person
    printf("anshul => %u\n", hash("anshul"));
    printf("venom => %u\n", hash("venom"));
    printf("rohit => %u\n", hash("rohit"));
      person* found_person = lookup("anshul");
    if (found_person) {
        printf("Found: %s, Age: %d\n", found_person->name, found_person->age);
    } else {
        printf("Not found\n");
    }
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 13

// Person structure definition
typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person* next;
} person;

// Hash table array
person* hash_table[TABLE_SIZE];

// Hash function
unsigned int hash(char* name) {
    int len = strnlen(name, MAX_NAME);
    unsigned int prime = 7;
    unsigned int hash_value = 0;
    
    for (int i = 0; i < len; i++) {
        hash_value = hash_value * prime + name[i];
    }
    hash_value = hash_value % TABLE_SIZE; // Ensure it fits in the hash table size
    return hash_value;
}

// Insert function for hash table
bool insert(person* p) {
    if (p == NULL) return false;
    unsigned int index = hash(p->name);
    p->next = hash_table[index]; // Point the new person to the current first element at this index
    hash_table[index] = p;       // Update the hash table to point to the new person
    return true;
}
// Lookup function to find a person in the hash table
person* lookup(char* name) {
    unsigned int index = hash(name);
    person* temp = hash_table[index];
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp; // Person found
        temp = temp->next; // Move to the next person in the chain
    }   
    return NULL; // Person not found
}
// Initialize the hash table to NULL
void init_hashtable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

int main() {
    init_hashtable(); // Initialize the hash table
    
    // Creating person instances
    person anshul = {.name = "anshul", .age = 25, .next = NULL};
    person venom = {.name = "venom", .age = 18, .next = NULL};
    person rohit = {.name = "rohit", .age = 19, .next = NULL};
    
    // Inserting persons into the hash table
    insert(&anshul);
    insert(&venom);
    insert(&rohit);

    // Display the hash values for each person
    printf("anshul => %u\n", hash("anshul"));
    printf("venom => %u\n", hash("venom"));
    printf("rohit => %u\n", hash("rohit"));
      person* found_person = lookup("anshul");
    if (found_person) {
        printf("Found: %s, Age: %d\n", found_person->name, found_person->age);
    } else {
        printf("Not found\n");
    }
    return 0;
}
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
