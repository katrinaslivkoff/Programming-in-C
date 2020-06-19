#include <stdio.h>

int main(void) {

  int fiveDigitNum;
  int num1, num2, num3, num4, num5, num6, num7, num8;

  printf("Enter Five Digit Number: ");
  scanf("%d", &fiveDigitNum);

  num1 = fiveDigitNum / 10000;
  // num1 = 12321 / 10000 = 1
  num2 = fiveDigitNum / 1000; 
  // num2 = 12321 / 1000 = 12
  num3 = num2 % 10;
  // num3 = 12 % 10 = 2
  num4 = fiveDigitNum / 100;
  // num4 = 12321 / 100 = 123
  num5 = num4 % 10;
  // num5 = 123 % 10 = 3
  num6 = fiveDigitNum / 10;
  // num6 = 12321 / 10 = 1232
  num7 = num6 % 10;
  // num7 = 1232 % 10 = 2
  num8 = fiveDigitNum % 10;
  // num8 = 12321 % 10 = 1

  if(num1 == num8 && num3 == num7) {
  // if 1 = 1, and 2 = 2, it is a palimdrome!
    printf("The number ");
    printf("%u", fiveDigitNum);
    printf(" is a palindrome!");
  }
  else {
    printf("The number ");
    printf("%u", fiveDigitNum);
    printf(" is a not palindrome.");
  }

  // 12321 was a palidrome
  
}