#include <stdio.h>

#define FLOOR_SIZE 50
#define X_POSITION 25	// start in the middle
#define Y_POSITION 25	// start in the middle

int Floor[FLOOR_SIZE][FLOOR_SIZE] = { {0} }; // initialize floor to 0

int xPos = X_POSITION;
int yPos = Y_POSITION;
enum Pen { PEN_DOWN, PEN_UP };

void walk(int direction, int pen);
void printMatrix(void);
int getInput(void);
int changeDirection(int direction);

int main() {
  int input;
  int pen = PEN_DOWN; // change pen to down
  int direction = 0; // starting at 0 degrees

  // while the pen is up
  while (1) {
	  input = getInput(); // get the input

	  switch (input) {
	    // enter 1, set pen to down
      case 1:
	      pen = PEN_DOWN;
	      break;
      // enter 2, set pen to up
	    case 2:
	      pen = PEN_UP;
	      break;
      // enter 3, turn right
	    case 3:
        // subtract 90
	      direction -= 90;
        // determine if turn right or left
	      direction = changeDirection(direction); 
	      printf("direction in degree: %d\n", direction);
	      break;
      // enter 4, turn left
	    case 4:
        // add 90
	      direction += 90;
        // determine if turn left or right
	      direction = changeDirection(direction);
	      printf("direction in degree: %d\n", direction);
	      break;
      // enter 5, walk a certain amount of numOfStepss forward
	    case 5:
	      walk(direction, pen);
	      break;
      // enter 6, print matrix
	    case 6:
	      printMatrix();
	      break;
      // enter 9, end so print matrix
	    case 9:
	      printMatrix();
	      break;
      // if anything else entered, invalid
	    default:
	      printf("Invalid input\n");
	  }			
  }			
}

int changeDirection(int direction){
  int newDir;

  // if direction entered is less than 0, add negative to direction
  // -90 entered so now 270
  if (direction < 0){
	  newDir = 360 + direction;
  }
  // if direction is greater than or eqaul to 360, subtract 360 from it
  // 360 entered so now 0
  else if (direction >= 360){
	  newDir = direction - 360;
  }
  // if anything entered between 0-359, then new direction is the direction
  // 60 = 60
  else{
	  newDir = direction;
  }
  // return the direction
  return newDir;
}

void walk(int direction, int pen){
  int numOfSteps;
  int i;
  int newX;
  int newY;

  // if no direction, x is positive and y is nothing
  if (direction == 0) {
	  newX = 1;
	  newY = 0;
  } 
  // if direction is 90, x is nothing and y is negative
  else if (direction == 90) {
	  newX = 0;
	  newY = -1;
  } 
  // if direction is 180, x is negative and y is nothing
  else if (direction == 180) {
  	newX = -1;
	  newY = 0;
  } 
  // if direction is 270, x is nothing and y is positive
  else if (direction == 270) {
	  newX = 0;
	  newY = 1;	
  }

  printf("How many steps? ");
  scanf("%d", &numOfSteps);

  for (i = 0; i < numOfSteps; i++) {
    // 25 +/- 1
    // 25 +/- 0
    xPos += newX;
    // if negative x, set x to 0
	  if (xPos < 0) {
	    xPos = 0;
	  } 
    // if x greater than 50, set x to 50
    else if (xPos > FLOOR_SIZE) {
	    xPos = FLOOR_SIZE;
	  }
    // 25 +/- 1
    // 25 +/- 0
	  yPos += newY;
    // if negative y, set y to 0
	  if (yPos < 0) {
	    yPos = 0;
	  } 
    // if y greater than 50, set y to 50
    else if (yPos > FLOOR_SIZE) {
	    yPos = FLOOR_SIZE;
	  }
    // if the pen is up, the floor is set to 1
	  if (pen == PEN_UP) {
	    Floor[yPos][xPos] = 1;
	  }
  }
}

// get the input of user
int getInput(void){
    int input;
    printf("\n"
	   "1) Pen up\n"
	   "2) Pen down\n"
	   "3) Turn right\n"
	   "4) Turn left\n"
	   "5) Move forward x amount of steps\n"
	   "6) Print matrix\n" 
     "9) End\n\n" "Insert command: ");
    scanf("%d", &input);
    return input;
}

// print the matrix
void printMatrix(void){
  int i, j;

  for (i = 0; i < FLOOR_SIZE; i++) {
	  for (j = 0; j < FLOOR_SIZE; j++){
	    printf(Floor[i][j] ? "#" : ".");
    }
	  printf("\n");
  }

  printf("\n");
}