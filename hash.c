#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* entries[TABLE_SIZE];
} HashTable;

HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
    return table;
}

void insert(HashTable* table, int key, int value) {
    int index = key%TABLE_SIZE;
    while (table->entries[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    table->entries[index] = newEntry;
}

int search(HashTable* table, int key) {
    int index = key % TABLE_SIZE;
    while (table->entries[index] != NULL) {
        if (table->entries[index]->key == key) {
            return table->entries[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

int Quadsearch(HashTable* table, int key) {
    int index = key % TABLE_SIZE;
    int i = 1;

    while (table->entries[index] != NULL) {
        if (table->entries[index]->key == key) {
            return table->entries[index]->value;
        }
        index = (index + i*i) % TABLE_SIZE;
        i++;
    }

    return -1;
}

void display(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->entries[i] != NULL) {
            printf("Key: %d, Value: %d\n", table->entries[i]->key, table->entries[i]->value);
        }
    }
}

int main() {
    int n,i,k,v;
    HashTable* table = createHashTable();
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter key and value:");
        scanf("%d %d",&k,&v);
        insert(table,k,v);
    }
    display(table);

    int searchKey;
    printf("Enter search key for linear probing:");
    scanf("%d",&searchKey);
    int searchResult = search(table, searchKey);
    if (searchResult != -1) {
        printf("Value for key %d: %d\n", searchKey, searchResult);
    } else {
        printf("Key %d not found\n", searchKey);
    }

    printf("Enter search key for quadratic probing:");
    scanf("%d",&searchKey);
    searchResult = Quadsearch(table, searchKey);
    if (searchResult != -1) {
        printf("Value for key %d: %d\n", searchKey, searchResult);
    } else {
        printf("Key %d not found\n", searchKey);
    }
    return 0;
}
