#include "double_linked_list.h"
#include <stdio.h>

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

  printf("succses insert\n");
  c = extract(list,0);
  printf("c is: %s\n",c); // should print "a"
  c = extract(list,0);
  printf("c is: %s\n",c); // should print "d"
  c = extract(list,0);
  printf("c is: %s\n",c); // should print "b"

  return 0;
}
