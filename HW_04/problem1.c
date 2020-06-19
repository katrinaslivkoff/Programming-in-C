#include <stdio.h>
#include<string.h>

// defines list of variables under the name Employee
struct Employee {
  char name[50];
  int id;
  char jobTitle[50];
};


int main(){
  int i, j; 
  int limit = 5;
  struct Employee obj[5], temp;

  // gets the inputs of the ID, name, and job title
  // stops at 5 employees
  for(i = 0; i < limit; i++){
    printf("\nEnter Employee ID: ");
    scanf("%d",&obj[i].id);
    printf("\nEnter Name: ");
    scanf("%s",obj[i].name);
    printf("\nEnter Job Title: ");
    scanf("%s",obj[i].jobTitle);
  }

  // places each name in descending alphabetic order
  for(i = 0; i < limit - 1; i++){
    for(j = i + 1; j < limit; j++){
      if(strcmp(obj[i].name, obj[j].name) < 0){
        temp = obj[i];
        obj[i] = obj[j];
        obj[j] = temp;
      }
    }
  }

  // prints the resulting list in descending alphabetic order
  for(i = 0; i < limit; i++){
    printf("\nEmployee ID:%d",obj[i].id);
    printf("\nEmployee Name:%s",obj[i].name);
    printf("\nEmployee Job description:%s",obj[i].jobTitle);
  }

  return 0;
}

