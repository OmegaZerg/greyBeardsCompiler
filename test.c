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

void testHashMap(hashMap_t *hashmap) {
    puts("Hello from inside of test hashmap!");
}