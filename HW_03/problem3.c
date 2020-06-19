#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveTheTortoise(int *);
void moveTheHare(int *);
void currentPos(int *, int *);

int main() { 
   int tortoise = 1, hare = 1;
   int timer = 0;
   int winner; 

   srand( time( NULL ) );

   //from the textbook
   printf("ON YOUR MARK, GET SET\n");
   printf("BANG               !!!!\n");
   printf("AND THEY'RE OFF    !!!!\n");
   
   while ( tortoise != 70 && hare != 70 ) {    
      moveTheTortoise(&tortoise);
      moveTheHare(&hare);
      currentPos(&tortoise, &hare);
      ++timer;
   }

   if ( tortoise >= hare ){
      printf("\nTORTOISE WINS!!! YAY!!!\n"f);
   }
   else{
      printf("Hare wins... ): \n" );
   }

   printf("Elapsed time: %d seconds", timer);
}

//moves the tortoise using a turtle pointer
void moveTheTortoise(int *turtlePtr){ 
   int x = rand() % 10 + 1;

   if ( x >= 1 && x <= 5 ){
      *turtlePtr += 3;
   }
   else if ( x == 6 || x == 7 ){
      *turtlePtr -= 6;
   }
   else{
      ++( *turtlePtr );
   }
   
   if ( *turtlePtr < 1 ){
      *turtlePtr = 1;
   }
   if ( *turtlePtr > 70 ){
      *turtlePtr = 70;
   }
}

//moves the hare using a hare pointer
void moveTheHare( int *harePtr ){ 
   int y = rand() % 10 + 1;

   if ( y == 3 || y == 4 ){
      *harePtr += 9;
   }
   else if ( y == 5 ){
      *harePtr -= 12;
   }
   else if ( y >= 6 && y <= 8 ){
      ++( *harePtr );
   }
   else if ( y == 10 ){
      *harePtr -= 2;
   }

   if ( *harePtr < 1 ){
      *harePtr = 1;
   }
   if ( *harePtr > 70 ){
      *harePtr = 70;
   }
}

//the current position of the trurtle and hare
void currentPos( int *turtlePtr, int *harePtr ){ 
   int count;
   
   for (count = 1; count < 71; count++) {
      if (count == *turtlePtr && count == *harePtr){
         printf( "OUCH!!!" );
      }
      else if (count == *harePtr){
         printf("H");
      }
      else if (count == *turtlePtr){
         printf("T");
      }
      else{
         printf(" ");
      }
   }

   printf("\n");
}