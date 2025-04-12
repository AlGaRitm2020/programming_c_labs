
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int args, char* argv[]){
  // char input[] = "2332";
  size_t bufsize=8, charsCount;
  char* input = (char*)malloc(sizeof(char)*bufsize);

  // getch
  charsCount= getline(&input,&bufsize, stdin);
  int current=0;
  int old=0;
  char last='+';
  int wait = 0;

  for (int i=0; i < charsCount; i++){
    if (isdigit(input[i]) && !wait) {
      current = atoi(&input[i]);
      printf("%c - digit; current = %d; old=%d\n", input[i], current, old); 
      wait=1;
    }
    else if ( (input[i] == '+') || (input[i] == '-') || (input[i] == '\n')) {
      wait=0;
      if (last == '+') {
        old += current;
      }
      else {
       old -= current;
      }
      last = input[i];
      current=0;

      printf("%c - operand\n", input[i]); 
    }
    // else if (input[i] == '\n') {
    //   if (last == '+') {
    //     old = old+ current;
    //   }
    //   else {
    //     old = old -current;
    //   }
    //   current = 0;
    // }
      
  }
  printf("sum: %d\n",old);
 return 0;

}
