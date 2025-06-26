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

void summonTextNode(textNode_t *node) {
    char *type;
    switch(node->textType) {
        case 0:
            type = "PARAGRAPH";
            break;
        case 1:
            type = "HEADING";
            break;
        case 2:
            type = "CODE";
            break;
        case 3:
            type = "QUOTE";
            break;
        case 4:
            type = "UNORDERED_LIST";
            break;
        case 5:
            type = "ORDERED_LIST";
            break;
        default:
            type = "UNKNOWN - Uh oh, check your spellbook";
    }
    if (*node->url == '\0') {
        printf("~Text Node~\nType: %s\nContents: %s\nURL: None\n", type, node->contents);
    } else {
        printf("~Text Node~\nType: %s\nContents: %s\nURL: %s\n", type, node->contents, node->url);
    }
}

bool textNodeCompare(textNode_t *node1, textNode_t *node2) {
    if (node1->textType == node2->textType && node1->contents == node2->contents && node1->url == node2->url) {
        return true;
    } else {
        return false;
    }
}