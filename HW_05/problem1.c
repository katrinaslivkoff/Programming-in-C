#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//from the textbook
struct stackNode { 
  int data;
  struct stackNode *nextPtr;
};

//from the textbook
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

//from the textbook
int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);
void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

//evaluates the postfix expression
int evaluatePostfixExpression(char *expr) {
    int i = 0; 

    StackNodePtr s = NULL;

    while(expr[i] != '\0'){
        if(isdigit(expr[i])){ 
          push(&s, (expr[i]-'0')); 
        }
        if(expr[i]=='+' || expr[i]=='-'|| expr[i]=='*' ||
         expr[i]=='/' || expr[i]=='^' || expr[i] =='%'){
        int x = pop(&s);
        int y = pop(&s);  
        
        int calc = calculate(y, x, expr[i]);
        push(&s, calc);
      }
      i++;
    }
    return pop(&s);
}
 
//calculates the expression of op1 and op2
int calculate(int op1, int op2, char operator) {
  if(operator == '+') {
    return op1 + op2;
  } else if(operator == '-') {
    return op1 - op2; 
  } else if(operator == '*') {
    return op1 * op2;
  } else if(operator == '/') {
    return op1/op2;
  } else if(operator == '%') {
    return op1 % op2;
  } else if(operator == '^') {
    return pow(op1, op2);
  } else {
    printf("Invalid operator.");
    return 0;
  }
}

//pushes the value on the stack
void push(StackNodePtr *topPtr, int value) {
  StackNodePtr newPtr = malloc(sizeof(StackNode));

  if(newPtr != NULL) {
    newPtr->data = value;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr; 
  } else {
      printf("%d not inserted. No memory available.\n", value);
  }
}

//pops the value on the stack
int pop(StackNodePtr *topPtr) {
  StackNodePtr tempPtr = *topPtr;
  int popValue = (*topPtr)->data;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popValue; 
}

//determines if the stack is empty
int isEmpty(StackNodePtr topPtr) {
  return topPtr == NULL;
}

//prints the stack
void printStack(StackNodePtr topPtr) {
  if(topPtr == NULL) {
    puts("The stack is empty.\n");
  } else {
    puts("The stack is: ");

  while(topPtr != NULL) {
    printf("%d --> ", topPtr->data);
    topPtr = topPtr->nextPtr;
  }
    puts("NULL\n");
  }
}

//main method to get the users input and evaluate it
int main(void) {
    char pf[250];
    printf("\nEnter postfix expression:\n");
    scanf("%s", pf);

    int len = strlen(pf);
    pf[len] = '\0';  

    printf("Result: %d", evaluatePostfixExpression(pf));
    printf("\n");
}


/*
  Enter postfix expression:
  6 2 + 5 * 8 4 / -
  Result: 6

*/
