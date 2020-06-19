#include <stdio.h>

unsigned packCharacters(unsigned c1, char c2);

void display(unsigned val);

int main(void){
      char a, b;
      unsigned result;

	  // gets two characters to be represented in bits
      printf("Enter any two characters:\n\n");

      printf("Enter the %s character: ", "first");
      scanf("%c", &a);
      getchar();

      printf("Enter the %s character: ", "second");
      scanf("%c", &b);
      getchar();

      printf("\nRepresentation of '%c' in bits as an unsigned integer is:\n", a);
      display(a);

      printf("\nRepresentation of '%c' in bits as an unsigned integer is:\n", b);
      display(b);

      unsigned ch = a;

      result = packCharacters(ch, b);

      printf("\nRepresentation of '%c\' and '%c\' "
            "packed in an unsigned integer is:\n", a, b);

      display(result);
      getchar();
}

// method to combine two characters into one bit value
unsigned packCharacters(unsigned c1, char c2){
      unsigned pack = c1;
      pack <<= 8;
	  // OR operator
      pack |= c2;
      return pack;
}

// method to dispplay a character as a number in bits
void display(unsigned val){
      unsigned c;
      unsigned mask = 1 << 31;
      printf("%7u = ", val);

      for (c = 1; c <= 32; c++){
            val & mask ? putchar('1') : putchar('0');
            val <<= 1;
            if (c % 8 == 0){
                  printf(" ");
            }
      }
      putchar('\n');
}