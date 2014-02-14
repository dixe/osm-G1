#include "double_linked_list.h"
#include <stdio.h>
#include <string.h>

// declare match_a function
bool match_a(item * thing);

int main(){

  char * a = "a";
  char * b = "b";
  char * d = "d";
  char * c ;



  dlist* list = (dlist*)init_dlist();

  insert(list, a, 0); // insert 'a' at head
  insert(list,b,0);
  c = extract(list,1);
  printf("c is: %s\n",c); // should print "a"

  c = extract(list,1);  //should be empty now
  printf("c is: %s\n",c); // should print "b"

  insert(list, b, 0); // insert 'b' at head

  printf("c is: %s\n",c); // should print "b"
  c = extract(list,0);  //should be empty now

  printf("we insert 3 new b,d,a\n");

  insert(list, b, 0); // insert 'b' at head
  insert(list, d, 0); // insert 'd' at head
  insert(list, a, 0); // insert 'a' at head

  reverse(list);

  int test = ( (int) search(list,match_a));
  if(test ){
    printf("We found a 'a'\n");
  }

  c = extract(list,0);
  printf("c is: %s\n",c); // should print "b"
  c = extract(list,0);
  printf("c is: %s\n",c); // should print "d"
  c = extract(list,0);
  printf("c is: %s\n",c); // should print "a"

  return 0;
}


//matches on 'a'
bool match_a(item *thing){
  // 'a' is type int
  if(thing == NULL){
    return 0;
  }

  // se if we have a "a"
  if( strcmp((char*) thing,"a")){
    return 1;
  }

  return 0;

}
