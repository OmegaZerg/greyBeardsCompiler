#include <stdio.h>
#include <stdlib.h>
#include "ObeliskNode.h"
#include "PhylacteryCache.h"

void testTextNode(textNode_t *node1, textNode_t *node2) {
    puts("\nTesting manual printing of textnode:");
    printf("New Node text: %s\n", node1->contents);
    if (*node1->url == '\0') {
        printf("New Node url: None\n");
    }
    puts("\nTesting function printing of textnode via 'printTextNode':");
    printTextNode(node1);

    puts("\nTesting function compare of textnode via 'textNodeCompare':");
    puts("The following should evaluate to false (0), as the input nodes have different text types:");
    printf("test: %d\n", textNodeCompare(node1, node2));
}

//hashmap->table[0]->value just segfaults everytime for some reason. Have done an hour of troubleshooting and getting nowhere today. Better luck next time.
//Looks to be something with the hashmap struct and the table it is using possibly. Added testing from within the insert hashmap and the KV pairs seem to be doing the correct things.
void testHashMap(hashMap_t *hashmap, char *testKey) {
    puts("Hello from inside of test hashmap!");
    printf("The length of hashmap is: %d\n", hashmap->length);
    printf("Size of value: %ld", sizeof(hashmap->table[0]->value));
    printf("Hashmap item 1: %s\n", hashmap->table[0]->value);
    
    //char *value = getValue(hashmap, testKey);
    //printf("The value for key {%s} is: %s\n", testKey, value);
}