#include <stdio.h>
#include <math.h>

int main(void) {

  int binaryNum;
  int dec = 0;
  int rem;

  printf("%s", "Enter a binary number: ");
  scanf("%d", &binaryNum);

  for(int i = 0; binaryNum != 0; ++i ) {
    rem = binaryNum % 10; 
    // 101 % 10 = 1; 10 % 10 = 0; 1 % 10 = 1
    binaryNum = binaryNum / 10; 
    // 101 / 10 = 10; 10 / 10 = 1; 1 / 10 = 0
    dec = dec + rem * pow(2, i); 
    // 0 + 1 * 2^0 = 1; 1 + 0 * 2^1 = 1; 1 + 1 * 2^2 = 5
  }

  printf("Decimal value: %d\n ", dec);
  // prints 101 to equal the decimal value of 5
}