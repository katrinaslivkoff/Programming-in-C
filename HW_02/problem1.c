#include <stdio.h>

int main(void) {
  float farenheit, celsius;
  int choice;
 
  printf("\n1: Fahrenheit to Celsius."); 
  printf("\n2: Celsius to Fahrenheit.");
  printf("\nEnter either 1 or 2: ");
  scanf("%d",&choice);
 
  // if the user wants to convert F to C
  if(choice == 1) {
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f",&farenheit);
    // celsius to farenheit conversion
    celsius = (farenheit - 32) / 1.8;
    printf("Temperature in Celsius: %.2f",celsius);
  }
  // if the user wants to convert C to F
  else if(choice == 2) {
    printf("\nEnter temperature in Celsius: ");
    scanf("%f",&celsius);
    // farenheit to celsius conversion
    farenheit = (celsius * 1.8) + 32;
    printf("Temperature in Fahrenheit: %.2f",farenheit);
    }
    else {
        printf("\nChoice does not exist...");
    }
}