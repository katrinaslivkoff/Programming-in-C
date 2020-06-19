#include <stdio.h>

//copies the string using array subscripting
void array_subscripting(char s[],char d[]) {
  int character = 0;

  while (s[character] != '\0') {
    d[character] = s[character];
    character++;
  }

  d[character] = '\0';
}

int main() {
  char s[] = "My name is Katrina!", d[1000];

  printf("The string before copying: %s\n", s);
  
  array_subscripting(s, d);
  
  printf("After copying the string: %s\n", d);
}

