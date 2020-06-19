
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    int start = 0; // if start is 0, continue program, else quit
    int command; // commands 1-4

    int i, x, k;
    int temp, temp2;
    char *numTemp = NULL;
    char *numTemp2 = NULL;
    int j = 0;
    char name1[50], name2[50], name3[50], name4[50], name5[50], name6[50], name7[50], name8[50], name9[50], name10[50];
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
    int seatingSize; //seatingSize available
    int seatFound = 0;//0 unless seat found 1 seatnot found 2

    char *name[10]= { };
    int number[10] = { };

    printf("\n1) Add to waitlist\n");
    printf("2) Remove oldest entry which fits the size of the table to eliminate an entry that fits the table\n");
    printf("3) Show the list, name, and number, from oldest to newest\n");
    printf("4) Quit\n");
    printf("Input number 1, 2, 3, or 4: ");

    int counter = 0; // the number of the array in the group

    while (start == 0) {

        scanf("%d", &command); // read in the user input

        // if you want to add to the wait list...
        if (command == 1) 
        {
          // 10 counters because I set the maxium number of
          // people in the waiting list to 10
            if (counter < 10){

              if(counter == 0){
                printf("\nInput your name: ");
                scanf("%s",name1);

                printf("\nInput size of your group: ");
                scanf("%d", &num1); 

                // adds the new name at 0
                counter += 1; 
                name[counter - 1] = name1; 
                number[counter - 1] = num1;
              }
              else if(counter == 1){
                printf("\nInput your name: ");
                scanf("%s",name2); 

                printf("\nInput size of your group: ");
                scanf("%d", &num2);

                // adds the new name at 1
                counter += 1;
                name[counter - 1] = name2;
                number[counter - 1] = num2;
              }
              else if(counter == 2){
                printf("\nInput your name: ");
                scanf("%s",name3); 

                printf("\nInput size of your group: ");
                scanf("%d", &num3); 

                // adds the new name at 2
                counter += 1;
                name[counter - 1] = name3;
                number[counter - 1] = num3;
              }
              else if(counter == 3){
                printf("\nInput your name: ");
                scanf("%s",name4); 

                printf("\nInput size of your group: ");
                scanf("%d", &num4);

                // adds the new name at 3
                counter += 1;
                name[counter - 1] = name4;
                number[counter - 1] = num4;
              }
              else if(counter == 4){
                printf("\nInput your name: ");
                scanf("%s",name5); 

                printf("\nInput size of your group: ");
                scanf("%d", &num5); 

                // adds the new name at 4
                counter += 1;
                name[counter - 1] = name5;
                number[counter - 1] = num5;
              }
              else if(counter == 5){
                printf("\nInput your name: ");
                scanf("%s",name6); 

                printf("\nInput size of your group: ");
                scanf("%d", &num6);

                // adds the new name at 5
                counter += 1;
                name[counter-1] = name6; 
                number[counter-1] = num6; 
              }
              else if(counter == 6){
                printf("\nInput your name: ");
                scanf("%s",name7);

                printf("\nInput size of your group: ");
                scanf("%d", &num7);

                // adds the new name at 6
                counter += 1;
                name[counter-1] = name7; 
                number[counter-1] = num7; 
              }
              else if(counter == 7){
                printf("\nInput your name: ");
                scanf("%s",name8);

                printf("\nInput size of your group: ");
                scanf("%d", &num8);

                // adds the new name at 7
                counter += 1;
                name[counter-1] = name8; 
                number[counter-1] = num8; 
              }
              else if(counter == 8){
                printf("\nInput your name: ");
                scanf("%s",name9);

                printf("\nInput size of your group: ");
                scanf("%d", &num9);

                // adds the new name at 8
                counter += 1;
                name[counter-1] = name9; 
                number[counter-1] = num9; 
              }
              else if(counter == 9){
                printf("\nInput your name: ");
                scanf("%s",name10);

                printf("\nInput size of your group: ");
                scanf("%d", &num10);

                // adds the new name at 9
                counter += 1;
                name[counter-1] = name10; 
                number[counter-1] = num10; 
              }

          for (x = 0; x < counter - 1; x++){
            if (name[counter - 1] == name[x]){
              printf("Duplicate name...");
              counter -= 1;
            }
          }

      }
      else if (counter >= 10) {
        printf("Waitlist is full."); 
      }

      printf("\n1) Add to waitlist\n");
      printf("2) Remove oldest entry which fits the size of the table to eliminate an entry that fits the table\n");
      printf("3) Show the list, name, and number, from oldest to newest\n");
      printf("4) Quit\n");
      printf("Input number 1, 2, 3, or 4: ");
    }

    // if input is to remove
    else if (command == 2){
      printf("\nInput open seat size: ");
      scanf("%d", &seatingSize);

      for (i = 0; i < counter; i ++){
        if (seatFound == 0){
          if (number[i] <= seatingSize){
            for(k = i;k < counter - 1; k++){
              temp2 = number[counter - 1];
              temp = number[k];
              number[k] = number[k+1];
              number[k + 1] = temp;
            }
            number[i] = temp2;
            for(k = i;k < counter - 1; k++){
              numTemp2 = name[0];
              numTemp = name[k];
              name[k] = name[k+1];
              name[k + 1] = numTemp;
            }
            name[0] = numTemp2;
            counter -= 1;
            seatFound = 1;
            printf("Seat found!");
          }
        }
      }

      if (seatFound == 0){
        printf("\nNo waitlist matches table size");
      }
      seatFound = 0;

      printf("\n1) Add to waitlist\n");
      printf("2) Remove oldest entry which fits the size of the table to eliminate an entry that fits the table\n");
      printf("3) Show the list, name, and number, from oldest to newest\n");
      printf("4) Quit\n");
      printf("Input number 1, 2, 3, or 4: ");
    }

    // if input is to show the wait list
    else if (command == 3) {
      printf("\nCurrent waiting list: \n");
      printf("----------------------\n");

      while (j < counter) {
        printf("\nName: %s\t \n# of people: %d\n", name[j], number[j]);
        printf("\n");
        j += 1;
      }

      j = 0;

      printf("----------------------\n");

      printf("\n1) Add to waitlist\n");
      printf("2) Remove oldest entry which fits the size of the table to eliminate an entry that fits the table\n");
      printf("3) Show the list, name, and number, from oldest to newest\n");
      printf("4) Quit\n");
      printf("Input number 1, 2, 3, or 4: ");
     }

    // quit the program
    else if (command == 4){ 
      start = 1;
    }

    else{
      printf("\nInvalid input, try again \n");

      printf("\n1) Add to waitlist\n");
      printf("2) Remove oldest entry which fits the size of the table to eliminate an entry that fits the table\n");
      printf("3) Show the list, name, and number, from oldest to newest\n");
      printf("4) Quit\n");
      printf("Input number 1, 2, 3, or 4: ");
    }
  }

}
