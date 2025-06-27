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

typedef struct {
    char *tag;  //html tag
    char *contents;  //Plain text?
    void *children;  //array of pointers to leafNodes
    void *props;  //hashmap of K/V pairs representing the attributes for an HTML tag of this instance. Example: a link <a> tag might have {"href": "https://.google.com"}
} leafNode_t;

textNode_t *createTextNode(blockType_t textType, char *text, char *url);

void summonTextNode(textNode_t *node);

bool textNodeCompare(textNode_t *node1, textNode_t *node2);