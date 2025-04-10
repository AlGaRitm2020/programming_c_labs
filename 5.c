//#include <curses.h>
// #include <curses.h>
#include <stdio.h>
// #include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
  char arr[height][width];
    render(2,2);
    // initscr(); 
    // keypad(stdscr, TRUE); // Включить стрелки
   char c;
   system ("/bin/stty raw");
   int i=0; int j=0;
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

  // endwin();


  return 0;
}
