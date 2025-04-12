#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
  int value;
  struct Node* next;
} Node;

typedef struct Set {
  Node* table[SIZE];
  int size;
} Set;



int hash(int value) ;


void set_init(Set* set); 


void set_add(Set* set, int value);
void set_remove(Set* set, int value) ;
int set_contain(Set* set, int value); 

int set_len(Set* set) ;
int set_print(Set* set) ;

