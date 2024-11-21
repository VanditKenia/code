#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Size of the hash table

// Structure to represent a hash table entry
typedef struct HashEntry {
    int key;
    int isOccupied;  // 1 if the slot is occupied, 0 if empty
} HashEntry;

// Function to initialize the hash table
void initializeTable(HashEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].isOccupied = 0;  // Mark all slots as empty initially
    }
}

// Hash function: Maps a key to an index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table using quadratic probing
void insert(HashEntry table[], int key) {
    int index = hashFunction(key);
    int i = 0;  // To keep track of the number of collisions

    // Try to find an empty slot using quadratic probing
    while (table[index].isOccupied) {
        i++;
        index = (hashFunction(key) + i * i) % TABLE_SIZE;  // Quadratic probing
    }
    
    // Insert the key
    table[index].key = key;
    table[index].isOccupied = 1;
    printf("Inserted key %d at index %d\n", key, index);
}

// Search for a key in the hash table
int search(HashEntry table[], int key) {
    int index = hashFunction(key);
    int i = 0;  // To keep track of the number of collisions

    // Look for the key using quadratic probing
    while (table[index].isOccupied) {
        if (table[index].key == key) {
            return index;  // Found the key
        }
        i++;
        index = (hashFunction(key) + i * i) % TABLE_SIZE;  // Quadratic probing
    }
    
    return -1;  // Key not found
}

// Function to display the hash table
void displayTable(HashEntry table[]) {
    printf("Hash Table: \n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].isOccupied) {
            printf("Index %d: %d\n", i, table[i].key);
        }
    }
}

int main() {
    HashEntry table[TABLE_SIZE];
    initializeTable(table);  // Initialize the hash table
    
    int choice, key, index;
    
    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(table, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = search(table, key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 3:
                displayTable(table);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
