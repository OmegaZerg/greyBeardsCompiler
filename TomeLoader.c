#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ObeliskNode.h"


int main() {
    bool channeling = true;
    //future - we gonna loop and keep app window open until user selects exit. Not sure if a while loop is required but we will see!

    char *testText = "test text here";
    char *testURL = "\0"; //represents a null entry since c funcations do not allow for default parameters.

    printf("Hello, World!\n");
    textNode_t *newNode = createTextNode(PARAGRAPH, testText, testURL);
    printf("New Node text: %s\n", newNode->contents);
    if (*newNode->url == '\0') {
        printf("New Node url: None\n");
    }

    summonTextNode(newNode);

    return 0;
}