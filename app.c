#include <stdio.h>
#include <stdlib.h>
#include "cllist.h"

int main(void){
    HLLIST hllist;
    NODE *node, *pos_node;
    DATATYPE *val;
    if((hllist = create_llist()) == NULL){
        fprintf(stderr, "cannot create linked list!\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 10; ++i){
        if((node = add_tail(hllist, i)) == NULL)
        {
            fprintf(stderr, "cannot add item!\n");
            exit(EXIT_FAILURE);
        }
        if(i == 0)
            pos_node = node;
    }

    walk_llist_rev(hllist, NULL);
    // insert_prev(hllist, pos_node, 555);
    // walk_llist(hllist, NULL);

    remove_node(hllist, pos_node);
    walk_llist_rev(hllist, NULL);

    if((val = getp_item(hllist, 5)) == NULL)
    {
        fprintf(stderr, "cannot get item!\n");
        exit(EXIT_FAILURE);
    }
    printf("val: %d\n", *val);

    clear_llist(hllist);
     for(int i = 0; i < 10; ++i){
        if((node = add_tail(hllist, i)) == NULL)
        {
            fprintf(stderr, "cannot add item!\n");
            exit(EXIT_FAILURE);
        }
    }

    walk_llist(hllist, NULL);

    destroy_llist(hllist);

    return 0;
}