#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int deck[][FACES]);
void deal(unsigned int deck[][FACES], unsigned int hand[][2], const char *suit[], const char *face[]);
void pair(unsigned int hand[][2], const char *suit[], const char *face[]);
void threeKind(unsigned int hand[][2], const char *suit[], const char *face[] );
void fourKind(unsigned int hand[][2], const char *suit[], const char *face[] );
void flush(unsigned int hand[][2], const char *suit[], const char *face[] );
void straight(unsigned int hand[][2], const char *suit[], const char *face[]);

//main function
int main() {
  const char *suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };

  const char *face[FACES] = { "Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight","Nine", "Ten", "Jack", "Queen", "King" };

  unsigned int deck[SUITS][FACES];
  unsigned int hand[5][2];
  size_t row, column;

  for(row = 0; row < SUITS; ++row){
    for(column = 0; column < FACES; ++column){
      deck[row][column] = 0;
   }
  }

  srand(time(NULL));
 
  shuffle(deck);
  deal(deck, hand, suit, face);
  pair( hand, suit, face );
  threeKind(hand, suit, face);
  fourKind(hand, suit, face);
  flush(hand, suit, face);
  straight(hand, suit, face);

}

//shuffles the deck randomly
void shuffle(unsigned int deck[][FACES] ){
  size_t row, column;
  unsigned int card;

  for(card = 1; card <= CARDS; ++card){
    do{
      row = rand() % SUITS;
      column = rand() % FACES;
    } while(deck[row][column] != 0);
    deck[row][column] = card;
  }
}

//deals 5 cards
void deal(unsigned int deck[][FACES], unsigned int hand[][2], const char *suit[], const       char *face[]) {
  unsigned int i = 0;
  size_t card, row, column;

  puts("The hand is:\n");

  for(card = 1; card < 6; ++card){
    for(row = 0; row < SUITS; ++row){
      for(column = 0; column < FACES; ++column){
        if(deck[row][column] == card){
          hand[i][0] = row;
          hand[i][1] = column;
          printf("%5s of %-8s\n", face[column], suit[row]);
          ++i;
        }
      }
    }
  }
  puts("\n");
}

//determines if ther is a pair
void pair(unsigned int hand[][2], const char *suit[], const char *face[]) {
  unsigned int counter[FACES] = {0};
  size_t i, j;

  for(i = 0; i < 5; ++i){
    ++counter[hand[i][1]];
  }
  for(j = 0; j < FACES; ++j){
    if(counter[j] == 2){
      printf("The hand contains a pair of %ss.\n", face[j]);
    }
  }
}

//determines if there is three of a kind
void threeKind(unsigned int hand[][2], const char *suit[], const char *face[] ){
  unsigned int counter[FACES] = {0};
  size_t i, j;

  for(i = 0; i < 5; ++i){
    ++counter[hand[i][1]];    
  }
  for(j = 0; j < FACES; ++j){
    if(counter[j] == 3){
      printf("The hand contains a three of a kind of %ss.\n", face[j]);
    }
  }   
}

//determines if there is four of a kind
void fourKind(unsigned int hand[][2], const char *suit[], const char *face[] ){
  unsigned int counter[FACES] = {0};
  size_t i, j;
  
  for(i = 0; i < 5; ++i){
    ++counter[hand[i][1]];
  }
  for(j = 0; j < FACES; ++j){
    if(counter[j] == 4){
      printf("The hand contains a four of a kind of %ss.\n", face[j]);
    }
  }
}

//determines if there is a flush
void flush (unsigned int hand[][2], const char *suit[], const char *face[] ){
  unsigned int counter[SUITS] = {0};
  size_t i, j;

  for(i = 0; i < 5; ++i){
    ++counter[hand[i][1]];
  }
  for(j = 0; j < SUITS; ++j){
    if(counter[j] == 5){
      printf("The hand contains a flush containing %ss.\n", face[j]);
    }
  }

}

//determines if there is a straight
void straight(unsigned int hand[][2], const char *suit[], const char *face[]){
  unsigned int counter[5] = {0};
  unsigned int temp;
  size_t i, pass, comp;

  for(i = 0; i < 5; ++i){
    counter[i] = hand[i][1];
  }

  for(pass = 1; pass < 5; ++pass){
    for(comp = 0; comp < 4; ++comp){
      if(counter[comp] > counter[comp + 1]){
        temp = counter[comp];
        counter[comp] = counter[comp + 1];
        counter[comp + 1] = temp;
      }
    }
  }

  if(counter[4] - 1 == counter[3] &&  counter[3] - 1 == counter[2] && counter[2] - 1 == counter[1] && counter[1] - 1 == counter[0]){
    printf("The hand contains a straight from %s to %s.\n", face[counter[0]], face[counter[4]]);
  }
}