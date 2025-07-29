#ifndef CLINKED_LIST_H_
#define CLINKED_LIST_H_

#include <stddef.h>
#include <stdbool.h>

/*Typr Declerations*/

typedef int DATATYPE;

typedef struct tagNODE{
    DATATYPE val;
    struct tagNODE* prev;
    struct tagNODE* next;
}NODE;

typedef struct tagLLIST{
    NODE head;
    size_t count;
}LLIST, *HLLIST;

/*Funciton Prototypes*/

HLLIST create_llist(void);
NODE* insert_next(HLLIST hllist, NODE* node, DATATYPE val);
NODE* insertp_next(HLLIST hllist, NODE* node, const DATATYPE *val);
NODE* add_tail(HLLIST hllist, DATATYPE val);
NODE* addp_tail(HLLIST hllist, const DATATYPE *val);
NODE* add_head(HLLIST hllist, DATATYPE val);
NODE* addp_head(HLLIST hllist, const DATATYPE *val);
NODE* insert_prev(HLLIST hllist, NODE* node, DATATYPE val);
NODE* insertp_prev(HLLIST hllist, NODE* node, const DATATYPE *val);
void remove_node(HLLIST hllist, NODE* node);
DATATYPE *getp_item(HLLIST hlllist, size_t index);
bool walk_llist(HLLIST hllist, bool (*proc)(NODE *));
bool walk_llist_rev(HLLIST hllist, bool (*proc)(NODE *));
void clear_llist(HLLIST hllist);
void destroy_llist(HLLIST hllist);
/*Inline Function Definitions*/

static inline size_t count_llist(HLLIST hllist)
{
    return hllist->count;
}

#endif