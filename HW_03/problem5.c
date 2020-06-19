#include <stdio.h>

int main(){
  char amount[100];
  int i = 0, flag = 0, fraction = 0, k = 1;

  printf("Enter dollar amount: " );
  scanf("%s", &amount);

  for(i = 0; amount[i] != '\0'; i++){
    if(amount[i] == '.'){
      flag = 1;
      continue;
    }
    else {
	  //if the character is not '.', print out the numbers and fraction
      if(flag){
        fraction = fraction * 10 + (amount[i] - '0');
        k = k * 10;
      }
      else{
        switch (amount[i] - '0'){
          case 1: printf("ONE ");
          break;
          case 2: printf("TWO ");
          break;
          case 3: printf("THREE ");
          break;
          case 4: printf("FOUR ");
          break;
          case 5: printf("FIVE ");
          break;
          case 6: printf("SIX ");
          break;
          case 7: printf("SEVEN ");
          break;
          case 8: printf("EIGHT ");
          break;
          case 9: printf("NINE ");
          break;
          case 0: printf("ZERO ");
          break;

        }
      }
    }
  }
  printf("and %d/%d", fraction, k);
}