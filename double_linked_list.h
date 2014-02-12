#ifndef D_L_LIST_H#define D_L_LIST_Htypedef int bool;typedef void item; /*we store pointers */typedef struct node_ {  item *thing;  struct node_ *ptr;} node;typedef struct dlist_{  node *head, *tail;} dlist;void insert(dlist *this, item* thing, bool atTail);// Returns NULL if head is NUll, ie empty listitem* extract(dlist *this,bool atTail);void reverse(dlist *this);item* search(dlist *this, bool(*matches)(item*));//Free allocated space used in dlistvoid free_dlist(dlist *this);// initialize a new listdlist* init_dlist();#endif /* D_L_LIST_H*/