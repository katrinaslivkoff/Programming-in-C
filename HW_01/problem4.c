#include <stdio.h>

int main(void) {
  
  int input;
  // input = 3

  printf("Enter a number: ");
  scanf("%d", &input);

  int count = input - 1; 
  // count = 3 - 1 = 2

  for (int i = 0; i < input; i++) { 
  // if i < 3, continue (go through 3 time)
      for (int j = 0; j < count; j++){
        printf(" ");
        // if j < 2, continue and print " " 2 times
        // if j < 1, continue and print " " 1 time
        // if j < 0, so print nothing
      } 
      for (int j = 0; j <= i; j++){
        printf("* "); 
        // if j <= 0, so print "* " once after the 2 spaces
        // if j <= 1, so print "* " twice after the 1 space
        // if j <= 2, so print "* " three times 
      }
      printf("\n"); 
      count--; 
      // go to the next line, count = 2 - 1 = 1
      // go to the next line, count = 1 - 1 = 0
      // go to the next line, count = 0 - 1 = -1
  } 

  count = 1;

  for(int i = input - 1; i  > 0; i--){
  // if i = 3 - 1 = 2, 2 > 0, continue, loop through 2 times
    for(int j = 0; j < count; j++){
      printf(" ");
      // if j < 1, 0 < 1, so print " " once
      // if j < 1, 0 < 2, so print " " twice
    }
    for(int j = 0; j < i; j++){
      printf("* "); 
      // if j < 2, 0 < 2, so print "* " two times
      // if j < 1, 1 < 2, so print "* " one time
    }   
  printf("\n"); 
  count++; 
  // go to the next line, count = 1 + 1 = 2
  // go to the next line, count = 2 + 1 = 3
  }
}