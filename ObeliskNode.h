#include <stdbool.h>
#pragma once

typedef enum {
    PARAGRAPH,
    HEADING,
    CODE,
    QUOTE,
    UNORDERED_LIST,
    ORDERED_LIST,
} blockType_t;

typedef struct {
    blockType_t textType;
    char *contents;
    char *url;
} textNode_t;

textNode_t *createTextNode(blockType_t textType, char *text, char *url);

void summonTextNode(textNode_t *node);

bool textNodeCompare(textNode_t *node1, textNode_t *node2);