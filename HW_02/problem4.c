#include <stdio.h>
#include <string.h>

// defines the vowels as a, e, i, o, u
#define vowels(v) (v =='a' || v =='e' || v =='i' || v =='o' || v =='u')

int main() {
  char word[100]; // This character array will allow you                             
				  // to store 100 characters from index 0 to 99.
  int length; // initializes length
  int i, j, k; // initializes i, j, k

  printf("\nEnter your English word: ");
  scanf("%s", word);

  // calculates the length of a given word[100]
  length = strlen(word);

  // for loop to check for vowels
  for(j = 0; j < length; j++){
    // if there is a vowel at a certain part of the word
    // then i is set to j
  	if(vowels(word[j])){
 	    i = j;
      break;
    }
  }

  printf("\nYour word in Pig Latin is: ");

  // prints the word at i, when there is a vowel
  for(i = i; i < length; i++){
    printf("%c",word[i]);
  }

  // prints the word at k, the rest of the word
  for(k = 0; k < j; k++){
	  printf("%c",word[k]);
  }

  printf("ay\n\n");

}