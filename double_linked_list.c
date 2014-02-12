/* implementation of double linked list using XOR
*/

#include "double_linked_list.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

dlist* init_dlist(){

  // allocate space for the dlist
  dlist *list = malloc(sizeof(dlist));
  // init head and tail to null
  list->head = NULL;
  list->tail = NULL;

  return list;

}

void insert(dlist *this, item* thing, bool atTail){
  if(this == NULL){
    //error
    exit(1);
  }

  node *tmp = malloc(sizeof(node)); // create a new node to hold new data

  tmp->thing = thing;

  if (this->head ==NULL){ // empty list
    // set this head to tmp
    this->head = tmp;
    //set this tail to tmp
    this->tail = tmp;
    // set the pointer of head to null, since it is the end
    this->head->ptr = NULL;
  }
  else if(atTail){ //nonempty list insert at tail
    /*
     * Tail points to the element before it
     * first we update the current tail's pointer so it depends on the item before
     * and the new item. tail->ptr currently just points to the item behind it
     */
    this->tail->ptr =(void*)((unsigned int)tmp ^ (unsigned int)(this->head->ptr));
    //set tmp to point at current tail
    tmp->ptr = this->tail;
    // set tmp as the new tail
    this->tail = tmp;

  }
  else{ // non empty list insertion at head
    /* the head just points at the next elm
     * the current head gets pushed on down the list
     * we reset its pointer by "tmp xor what is point to"
     */
    this->head->ptr =(void*)((unsigned int)tmp ^ (unsigned int)(this->head->ptr));
    // set tmp to point at the current head
    tmp->ptr = this->head;
    //set head to tmp
    this->head = tmp;

  }
}


item* extract(dlist *this, bool atTail){
  item* item;

  if(this->head == NULL){
    printf("Head is NULL \n");
    return NULL;
  }

  // if head->ptr is NULL list only has head in it
  if(this->head->ptr == NULL){
    item = this->head->thing;
  }
  else if (atTail){
    item = this->tail->thing;
    printf("we got the item\n");
    /*
     * tails pointer points to the item just it, since tails pointer is item before xor 0
     * to remove the tail, we need to update the item befores pointer, so it does
     * not depend on tail
     */

    void* tmp = this->tail;

    this->tail = this->tail->ptr;

    // update tail so it xor'ed with 0 gives the corrent value

    this->tail->ptr = (void*) ((unsigned int) tmp ^ (unsigned int) this->tail->ptr);


  }
  else{

    item = this->head->thing;


    //get the item at head
    item = this->head->thing;
    /*
     * head's pointer is just the next item
     * the node after head, its pointer depends on head
     * and since the node after is going to be new head
     * we need to update its pointer
     */
    //temp store the old head
    void* tmp = this->head;
    // set new head
    this->head = this->head->ptr;
    //update new heads pointer, so that xor'ed with 0 it gives the correct value
    this->head->ptr = (void*)((unsigned int) tmp ^ (unsigned int)this->head->ptr);

  }


  if(item ==NULL){
    printf("Item is NULL\n");
  }

  return item;

}

void reverse(dlist *this){
  /*
   * To reverser the list, we just switch head and tail around
   */

  // store current head in tmp
  node * tmp = this->head;
  // set tail as new head
  this->head = this->tail;
  //set the old head as new tail
  this->tail = tmp;

}

item* search(dlist *this, bool(*matches)(item*)){

  // we start at the head
  node* cur = this->head;
  int done = 0;

  while(cur != NULL || !done){

    // if they match, we are done and can return current item
    if (matches(cur->thing)){
      done = 1;
    }
    else{ // else we check the next elm
      // when we get to the last elm, we xor a pointer with it self, and get NULL
      cur = (void*) ((unsigned int) cur ^ (unsigned int)cur->ptr);
    }
  }

  return cur->thing;
}

void free_dlist(dlist *this){
  dlist *tmp;
  while(this->head != NULL){
    // extract the head
    tmp = extract(this,1);
    // free the node
    free(tmp);
  }
}
