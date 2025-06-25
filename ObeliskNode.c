#include "ObeliskNode.h"
#include <stdio.h>
#include <stdlib.h>

textNode_t *createTextNode(blockType_t textType, char *text, char *url) {
    // malloc stuff here?? Preferrable instead of on function call
    // textNode_t node = {.textType, .text, .url};
    textNode_t *newNode = malloc(sizeof(textNode_t));
    if (newNode == NULL){
        printf("Unable to allocate memory");
        return NULL;
    }
    newNode->textType = textType;
    newNode->contents = text;
    newNode->url = url;
    return newNode;
}

bool textNodeCompare(textNode_t *node1, textNode_t *node2) {
    if (node1->textType == node2->textType && node1->contents == node2->contents && node1->url == node2->url) {
        return true;
    } else {
        return false;
    }
}