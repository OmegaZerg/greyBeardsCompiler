#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ObeliskNode.h"
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

    return 0;
}