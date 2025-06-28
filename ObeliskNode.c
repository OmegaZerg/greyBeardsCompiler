#include "ObeliskNode.h"
#include <stdio.h>
#include <stdlib.h>

/**************Text Node Block**************/
textNode_t *createTextNode(blockType_t textType, char *contents, char *url) {
    // malloc stuff here?? Preferrable instead of on function call
    // textNode_t node = {.textType, .text, .url};
    textNode_t *newNode = malloc(sizeof(textNode_t));
    if (newNode == NULL){
        printf("Unable to allocate memory for textNode.\nSummon Failed!\n");
        return NULL;
    }
    newNode->textType = textType;
    newNode->contents = contents;
    newNode->url = url;
    return newNode;
}

void printTextNode(textNode_t *node) {
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

int textNodeCompare(textNode_t *node1, textNode_t *node2) {
    if (node1->textType == node2->textType && node1->contents == node2->contents && node1->url == node2->url) {
        return 1;
    } else {
        return 0;
    }
}
/**************End Block**************/

/**************Leaf Node Block**************/
leafNode_t *createLeafNode(char *tag, char *contents, void *children, void *props) {
    leafNode_t *newNode = malloc(sizeof(leafNode_t));
    if (newNode == NULL){
        printf("Unable to allocate memory for leafNode! Summon Failed!\n");
        return NULL;
    }
    newNode->tag = tag;
    newNode->contents = contents;
    newNode->children = children;
    newNode->props = props;
    return newNode;
}
//still need to implement this
void printLeaftNode(leafNode_t *node) {
    return;
}

int leafNodeCompare(leafNode_t *node1, leafNode_t *node2) {
    if (node1->tag == node2->tag && node1->contents == node2->contents && node1->props == node2->props) {
        return 1;
    } else {
        return 0;
    }
}

/**************End Block**************/

/**************Parent Node Block**************/

/**************End Block**************/