#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PhylacteryCache.h"

//Hash Function - This currently uses a constant size 100 for now
unsigned int hash(char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % TABLE_SIZE;
}

hashMap_t *createHashMap() {
    hashMap_t *map = malloc(sizeof(hashMap_t));
    if (map == NULL){
        printf("Unable to allocate memory for Hash Map.\nSummon Failed!\n");
        return NULL;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
    return map;
}

//After inserting key/value into hashmap, we should be able to free memory of the original input constants as we create copies for our hashmap here.
int insert(hashMap_t *map, char *key, char *value) {
    unsigned int index = hash(key);
    keyValue_t *newKvPair = malloc(sizeof(keyValue_t));
    if (newKvPair == NULL){
        printf("Unable to allocate memory for Key/Value Pair.\nSummon Failed!\n");
        return -1;
    }
    newKvPair->key = strdup(key);
    newKvPair->value = strdup(value);
    newKvPair->next = map->table[index];
    //Possibly implement checks to ensure values written correctly?
    puts("New Key/Value pair added to hashmap.");
    return 0;
}

char *getValue(hashMap_t *map, char *key) {
    unsigned int index = hash(key);
    keyValue_t *pair = map->table[index];
    while (pair) {
        if (strcmp(pair->key, key) == 0) {
            return pair->value;
        }
        pair = pair->next;
    }
    puts("Key Not Found!");
    return NULL;
}

//Update value function needed

//Find KV pair function needed: would this just print out the KV pair if found? 

int freeHashMap(hashMap_t *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        keyValue_t *pair = map->table[i];
        while (pair) {
            keyValue_t *temp = pair;
            pair = pair->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(map);
    puts("Hashmap successfully released into the wild!");
    return 0;
}