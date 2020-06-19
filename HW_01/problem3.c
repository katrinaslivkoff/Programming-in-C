#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  
  char player1;

  int player1Wins = 0;
  int player2Wins = 0;

  srand ((int) time (NULL));

  for(int i = 1; i <= 10; i++) {
  // loop through 10 times
    printf("Enter P for paper, R for rock, or S for scissor: ");
    scanf("\n%c", &player1);
    // user inputs p, r, or s
    int player2 = rand() % 3 + 1;
    // player 2 is set to a randome value between 1 and 3
    printf("Player2 chose: %d\n", player2);
    // prints what the random value of player 2 was
    if(player1 == 'P' || player1 == 'p'){
      player1 = 1;
    }
    // sets player1 input to be 1 if entered P
    else if(player1 == 'R' || player1 == 'r'){
      player1 = 2;
    }
    // sets player1 input to be 2 if entered R
    else if(player1 == 'S' || player1 == 's'){
      player1 = 3;
    }  
    // sets player1 input to be 3 if entered s

    switch(player1){
    
      case 1:
      // player1 entered paper
      if(player2 == 2){
      // if player2 was rock, player1 wins
        printf("You win!\n\n");
        player1Wins++;
      }
      else if(player2 == 3){
      // if player2 was scissors, player2 wins
        printf("The computer wins.\n\n");
        player2Wins++;
      }
      else{
      // if player1 and player2 both were paper, then they tie
        printf("Draw.\n\n");
      }
      break;

      case 2:
      // player1 entered rock
      if(player2 == 1){
      // if player2 was paper, player2 wins
        printf("The computer wins.\n\n");
        player2Wins++;
      }
      else if(player2 == 3){
      // if player2 was scissor, player1 wins
        printf("You win!\n\n");
        player1Wins++;
      }
      else{
      // if player1 and player2 both were rock, then they tie
        printf("Draw.\n\n");
      }
      break;

      case 3:
      // player1 entered scissor
      if(player2 == 1){
      // if player2 was paper, player1 wins
        printf("You win!\n\n");
        player1Wins++;
      }
      else if(player2 == 2){
      // if player2 was rock, player2 wins
        printf("The computer wins.\n\n");
        player2Wins++;
      }
      else{
      // if player1 and player2 both were scissor, then they tie
        printf("Draw.\n\n");
      }
      break;

			case '\n':
			case '\t':
			case ' ':
			break;
	
			default:
				printf("%s", "\nIncorrect input entered.");
				puts(" Enter a new input.\n");
      break;
    }
  }

  if(player2Wins > player1Wins ){
  // if player 2 win count is greater than player 1 win count, then the computer wins
      printf("Computer wins %d to %d\n",player2Wins,player1Wins);
  }
  else if(player2Wins < player1Wins ){
  // if player 2 win count is less than player 1 win count, then the you win
      printf("You win %d to %d\n",player1Wins,player2Wins);
  }
  else if(player2Wins == player1Wins ){
  // if player 2 win count is equal to player 1 win count, then you tie with the computer
      printf("No winner it is a draw!\n");
  }
}
