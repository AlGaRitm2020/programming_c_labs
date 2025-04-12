//#include <curses.h>
// #include <curses.h>
#include <stdio.h>
// #include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "sett.h"

#define height 5 
#define width 10

void render(int vi, int hi) { // vi - vertical index, hi -horizontal index
  system("clear");
  //clear();
  for (int i =0; i < height; i++) {
    for (int j =0; j < width; j++)
      if (i == vi && j == hi)
        printf("#"); 
      else
        printf(".");
    printf("\n\r"); 
  }
  // refresh();
  
}

void print_rand_chars(char* arr, int size){
  for(int i=0; i<size; i++){
    printf("%c ", arr[i]);
    if (i % 6==5) 
      printf("\n");
  } 
}

int main(int argc, char *argv[])
{
  srand(time(0));
  char arr[height][width];
    render(2,2);
    // initscr(); 
    // keypad(stdscr, TRUE); // Включить стрелки
   char c;
   system ("/bin/stty raw");
   int i=2; int j=2;
   while((c = getchar()) !='q'){
    render(i,j);
    printf("char: %d\n\r",c); 
    switch (c) {
      case -1:
        continue;
      case 66 :
        printf("down\n\r");
        i++;
        break;
      case 65:
        printf("up\n\r");
        i--;
        break;
      case 68:
        printf("left\n\r");
        j--;
        break;
      case 67:
        printf("right\n\r");
        j++;
        break;
      }
    //if (f == 'C')
     // printf("goy\n"); 
   }
  system ("/bin/stty sane");
  printf("\n");
    

  char randChars[36];
  char r;
  // Set* set = malloc(sizeof(Set));
  Set* set = (Set*)malloc(sizeof(Set));
  set_init(set);
  for (int i=0; set_len(set) < 36;){
    // set_print(set);
    r = rand()%36;
    if (r<26)
      r+=65;
    else
      r+=48-26 ;

    if (!set_contain(set, r)) 
    {
      randChars[i++] = r;
      set_add(set, (int)r);
    }
  }
  free(set);

  print_rand_chars(randChars, 36);

  // for (char i=65; i<(char)255; i++)
  //   printf("%d %c\n",i, i);

    

  // endwin();


  return 0;
}
