#include <stdio.h>
#include <stdlib.h>
#include "cllist.h"

/*Static Function Declarations*/
static bool disp(NODE *);
/*Function Definitions*/

HLLIST create_llist(void)
{
    HLLIST hllist;

    if((hllist = (HLLIST)malloc(sizeof(LLIST))) == NULL)
        return NULL;

    hllist->head.next = &hllist->head;
    hllist->head.prev = &hllist->head;
    hllist->count = 0;

    return hllist;
}

NODE* insert_next(HLLIST hllist, NODE* node, DATATYPE val)
{
    NODE* new_node;

    if((new_node = (NODE*)malloc(sizeof(NODE))) == NULL)
        return NULL;
    new_node->val = val;
    
    node->next->prev = new_node;
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;

    ++hllist->count;

    return new_node;
}

NODE* insertp_next(HLLIST hllist, NODE* node, const DATATYPE *val)
{
    NODE* new_node;

    if((new_node = (NODE*)malloc(sizeof(NODE))) == NULL)
        return NULL;
    new_node->val = *val;
    
    node->next->prev = new_node;
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;

    ++hllist->count;

    return new_node;
}

NODE* insert_prev(HLLIST hllist, NODE* node, DATATYPE val)
{
    NODE* new_node;

    if((new_node = (NODE*)malloc(sizeof(DATATYPE))) == NULL)
        return NULL;
    
    new_node->val = val;

    node->prev->next = new_node;
    new_node->prev = node->prev;
    new_node->next = node;
    node->prev = new_node;

    ++hllist->count;
    return new_node;
}

NODE* insertp_prev(HLLIST hllist, NODE* node, const DATATYPE *val)
{
    NODE* new_node;

    if((new_node = (NODE*)malloc(sizeof(DATATYPE))) == NULL)
        return NULL;
    
    new_node->val = *val;

    node->prev->next = new_node;
    new_node->prev = node->prev;
    new_node->next = node;
    node->prev = new_node;

    ++hllist->count;
    return new_node;
}

NODE* add_tail(HLLIST hllist, DATATYPE val)
{
    return insert_prev(hllist, &hllist->head, val);
}

NODE* addp_tail(HLLIST hllist, const DATATYPE *val)
{
    return insert_prev(hllist, &hllist->head, *val);

}

NODE* add_head(HLLIST hllist, DATATYPE val)
{
    return insert_next(hllist, &hllist->head, val);
}

NODE* addp_head(HLLIST hllist, const DATATYPE *val)
{
    return insert_next(hllist, &hllist->head, *val);
}

void remove_node(HLLIST hllist, NODE* node)
{
   
    
    node->prev->next = node->next;
    node->next->prev = node->prev;

    --hllist->count;

    free(node);

}

DATATYPE *getp_item(HLLIST hlllist, size_t index)
{
    NODE* node;
    
    if(index >= hlllist->count)
        return NULL;

    node = hlllist->head.next;

    for(size_t i = 0; i < index; ++i)
        node = node->next;
    
    return &node->val;
}

bool walk_llist(HLLIST hllist, bool (*proc)(NODE *))
{
    bool retval = true;
    bool def_flag = false;

    if(proc == NULL){
        proc = disp;
        def_flag = true;
    }
    for(NODE* node = hllist->head.next; node != &hllist->head; node = node->next)
        if(!proc(node)){
            retval = false;
            break;
        }

    if(def_flag)
        putchar('\n');

    return retval;
}

bool walk_llist_rev(HLLIST hllist, bool (*proc)(NODE *))
{
    bool retval = true;
    bool def_flag = false;

    if(proc == NULL){
        proc = disp;
        def_flag = true;
    }
    
    for(NODE* node = hllist->head.prev; node != &hllist->head; node = node->prev)
        if(!proc(node)){
            retval = false;
            break;
        }
        
    if(def_flag)
        putchar('\n');

    return retval;
}

void clear_llist(HLLIST hllist)
{
    NODE *node, *temp_node;
    node = hllist->head.next;
    while(node != &hllist->head)
    {
        temp_node = node->next;
        free(node);
        node = temp_node;
    }
    hllist->head.next = &hllist->head;
    hllist->head.prev = &hllist->head;
    hllist->count = 0;
}

void destroy_llist(HLLIST hllist)
{
    //clear_llist(hllist);
    NODE *node, *temp_node;
    node = hllist->head.next;
    while(node != &hllist->head)
    {
        temp_node = node->next;
        free(node);
        node = temp_node;
    }
    free(hllist);
}

static bool disp(NODE *node){
    printf("%d ", node->val);
    fflush(stdout);

    return true;
}