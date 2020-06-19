#include <stdio.h>

//copies the string using pointers
void pointer_arithmetic(char *s,char *d){
  int character = 0;

  while (*(s+character) != '\0') {
    *(d + character) = *(s + character);
    character++;
  }

  *(d + character) = '\0';
}

int main(void){
  char *s = "My name is Katrina!", *d;
  printf("Before copying the string: %s\n", s);
  pointer_arithmetic(s,d);
  printf("After copying, the string: %s\n", d);
}