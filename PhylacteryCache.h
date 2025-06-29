#pragma once
#define TABLE_SIZE 100

typedef struct keyValue keyValue_t;

//Future improvment possibility: replace char * value with union that can handle various data types, namely char *, int, float.
typedef struct keyValue{
    char *key;
    char *value;
    keyValue_t *next;
} keyValue_t;

//Table size is a global constant 100 for now. Future improvment will likely see this changed to be a variable stored inside hashMap_t itself, that can be dynamically increased as the hashmap fills, and decreased and the hashmap empties.
typedef struct {
    keyValue_t *table[TABLE_SIZE];
    int length;
} hashMap_t;

unsigned int hash(char *key);

hashMap_t *createHashMap();

int insert(hashMap_t *map, char *key, char *value);

char *getValue(hashMap_t *map, char *key);

int freeHashMap(hashMap_t *map);