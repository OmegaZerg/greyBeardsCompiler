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

//I believe children can be removed on this one. Possibly only the html node and pa4rent node will be capable of having children. leafnodes may only be the last node. Need to think on this more.
typedef struct {
    char *tag;  //html tag
    char *contents;  //Plain text?
    void *children;  //array of pointers to leafNodes
    void *props;  //hashmap of K/V pairs representing the attributes for an HTML tag of this instance. Not a required field. Example: a link <a> tag might have {"href": "https://.google.com"}
} leafNode_t;

textNode_t *createTextNode(blockType_t textType, char *contents, char *url);

void printTextNode(textNode_t *node);

int textNodeCompare(textNode_t *node1, textNode_t *node2);


leafNode_t *createLeafNode(char *tag, char *contents, void *children, void *props);

void printLeaftNode(leafNode_t *node)

int leafNodeCompare(leafNode_t *node1, leafNode_t *node2);