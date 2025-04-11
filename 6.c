
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* two[] =       {"██████",
                     "    ██",
                     "██████",
                     "██    ",
                     "██████",
};

char* three[] = { 
                     "██████",
                     "    ██",
                     "  ████",
                     "    ██",
                     "██████",
};

char* one[] = { 
                     "  ██  ",
                     "████  ",
                     "  ██  ",
                     "  ██  ",
                     "██████",
};
void print_horizontal(char*** arr, int num_count) {
  for(int i=0; i < 5; i++) {
    
    for(int j=0; j < num_count; j++) {
      printf("%s ", arr[j][i]);
  }
    printf("\n");
  }
}

void print_vertical(char*** arr, int num_count) {
  for(int i=0; i < num_count; i++) {
    
    for(int j=0; j < 5; j++) {
      printf("%s\n", arr[i][j]);
  }
    printf("\n");
  }
}

int main(int args, char* argv[]){
  // char input[] = "2332";
  size_t bufsize=8, charsCount;
  char* input = (char*)malloc(sizeof(char)*bufsize);


  charsCount= getline(&input,&bufsize, stdin);
  if (charsCount == -1) return 1;
  char *** arr = (char***)malloc(sizeof(char)*5*6*charsCount);
  int digit_char=0;
  for (int i=0; i<(int)charsCount;i++){
    switch (input[i]) {
      case '1': 
        arr[i] = one;
        digit_char++;
        break;
      case '2': 
        arr[i] = two;
        digit_char++;
        break;
      case '3':
        arr[i] = three;
        digit_char++;
        break;
    }
  }
  // char usage[] = "Usage: "
  char* usage = (char*)malloc(sizeof(char)*100);
  sprintf(usage, "Usage: %s <horizontal | vertical>\n", argv[0]);

  if (args == 2) {
    if (strcmp(argv[1], "vertical") ==0)
      print_vertical(arr, (int)digit_char);
    else if (strcmp(argv[1], "horizontal") ==0 )
      print_horizontal(arr, (int)digit_char);
    else
     printf("%s", usage);
  }
  else
     printf("%s", usage);
//  print_horizontal(arr, (int)digit_char);

  free(usage);
  free(arr);
  free(input);
  return 0;

}
