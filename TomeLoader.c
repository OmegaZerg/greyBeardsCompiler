#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ObeliskNode.h"
#include "PhylacteryCache.h"
#include "test.h"


int main() {
    bool channeling = true;
    //future - we gonna loop and keep app window open until user selects exit. Not sure if a while loop is required but we will see!

    char *testText = "test text here";
    char *testURL = "\0"; //represents a null entry since c funcations do not allow for default parameters.

    printf("Hello, World from TomeLoader!\n");
    textNode_t *newNode1 = createTextNode(PARAGRAPH, testText, testURL);
    textNode_t *newNode2 = createTextNode(QUOTE, testText, testURL);

    testTextNode(newNode1, newNode2);

    //create KV first: 
    // char *key1 = "href";
    // char *value1 = "https://www.google.com";
    // char *key2 = "id";
    // char *value2 = "main-containe";
    // char *key3 = "style";
    // char *value3 = "color: blue; font-size: 24px;";

    // char *keys[] = {key1, key2, key3};
    // char *values[] = {value1, value2, value3};

    char *keys[] = {"href", "id", "style"};
    char *values[] = {"https://www.google.com", "main-container", "color: blue; font-size: 24px;"};

    //Create hashmap:
    hashMap_t *hashMapProps = createHashMap();

    //Insert KY pairs:
    //sizeof(keys) / sizeof(keys[0]) only works for arrays, so it works here but best case is to just track size of your arrays
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        printf("The size of keys is: %ld\n", sizeof(keys));
        int success = insert(hashMapProps, keys[i], values[i]);
        if (success == 0) {
            printf("Key {%s} and Value {%s} inserted into hashmap successfully!\n", keys[i], values[i]);
        }
    }
    char *testKey = "style";
    testHashMap(hashMapProps, testKey);

    return 0;
}