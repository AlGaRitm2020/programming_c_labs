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

int hash(int value) {
  return value % SIZE;
}

void set_init(Set* set) {
  for(int i=0; i < SIZE; i++)
    set->table[i] = NULL;
  set->size = 0;
}

void set_add(Set* set, int value){
  int index = hash(value); 
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next= NULL;

  Node* current = set->table[index];
  while (current!= NULL) {
    if (current-> value == value) {
      free(newNode);
      return; 
    }
    current = current->next;
  }
  newNode->next = set->table[index];
  set->table[index] = newNode;

  set->size++;

}

void set_remove(Set* set, int value) {
  int index = hash(value); 
  Node* previous = NULL; 
  Node* current = set->table[index];

  while (current!= NULL) {
    if (current-> value == value) {
      if (previous == NULL)
        set->table[index] = current->next;
      else
        previous->next = current->next;
      set->size--;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

int set_contain(Set* set, int value) {
  int index = hash(value);
  Node* current = set->table[index];
  while (current != NULL) {
    if (current->value == value)
      return 1;
    current = current->next;
  }
  return 0;
}

int set_len(Set* set) {
  return set->size; 
}

void set_print(Set* set) {
  printf("set have %d elements\n", set_len(set));
  for (int i=0; i < SIZE; i++) {
    printf("Hash=%d: ", i);
    Node* current = set->table[i];
    while(current!=NULL) {
      printf("%d ", current->value);
      current=current->next;
    }
    printf("NULL ... \n");
  }
}

int main() {
//  Set* set = (Set*)malloc(sizeof(Set));
  Set* set = (Set*)malloc(sizeof(Set));
  set_init(set);
  set_add(set, 5);
  set_add(set, 15);
  set_add(set, 25);
  set_add(set, 26);
  set_print(set);
  set_remove(set, 15);
  set_print(set);

  free(set);


  return 0;
}


