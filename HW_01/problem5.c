#include <stdio.h>

int main(void) {

  int input;
  int count = 1;
  int num;

  printf("Enter a number: ");
  scanf("%d", &input);

  for(int i = 1; i <= input; i++) {
  // i = 1, if i <= 3, loop 3 times
  // i = 2
  // i = 3
  // i = 4, 4 <= 3, so end for statement
    if(i%2 != 0) {
    // if 1%2 != 0, then go throught this
    // if 2%2 != 0, false so go to else statement
    // if 3%2 != 0, then go through this block
      for(int j = 1; j <= 2*i-1; j++) {
      // if j <= 2*1-1; 1 <= 1; loop through
      // if j <= 1; 2 <= 1, false so end for loop
      // if j <= 2*3-1; 1 <= 5; loop through
      // if j <= 5; 2 <= 5; loop through
      // if j <= 5; 3 <= 5; loop through
      // if j <= 5; 4 <= 5; loop through
      // if j <= 5; 5 <= 5; loop through
      // if j <= 5; 6 <= 5; so end for statement
        if(i%2 != 0 && j%2 == 0) {
        // if 1%2 != 0 and 1%2 == 0; so go to else
        // if 3%2 != 0 and 1%2 == 0; so go to else
        // if 3%2 != 0 and 2%2 == 0; so loop thorugh
        // if 3%2 != 0 and 3%2 == 0; so go to else
        // if 3%2 != 0 and 4%2 == 0; so loop thorugh
        // if 3%2 != 0 and 5%2 == 0; so go to else
          printf("*");
          // print * after 4 (4*)
          // print * after 5 (4*5*)
        }
        else {
          printf("%d",count);
          // print 1
          // print 4
          // print 5 after * (4*5)
          // print 6 after * (4*5*6)
          count++;
          // count = 1 + 1 = 2
          // count = 5
          // count = 6
          // count = 7
        }
      }
      printf("\n");
      // go to next line after (1)
    }
    else {
      num =((i*i+i)/2);
      // num = 2*2+2/2 = 3
      for(int j = 1; j <= 2*i-1; j++) {
      // j = 1; 1 <= 2*2-1; 1 <= 3; loop through
      // j = 2; 2 <= 3, loop through
      // j = 3; 3 <= 3, loop through
      // j = 4; 4 <= 3, false so end for statement
        if(i%2 == 0 && j%2 == 0) {
        // 2%2 = 0 and 1%2 = 0; false so go to else statement
        // 2%2 = 0 and 2%2 = 0; true so...
        // 2%2 = 0 and 3%2 = 0; false so go to else statement
          printf("*");
        // print * after 3 (3*)
        }
        else {
          printf("%d",num);
          // print 3
          // print 2 after * (3*2) 
          num--;
          // num = 2
          // num = 1
          count++;
          // count = 3
          // count = 4
        }
      }
      printf("\n");
      // go to next line after (3*2)
    }
  }
}