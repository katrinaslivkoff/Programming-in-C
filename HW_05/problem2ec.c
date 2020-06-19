#include <stdio.h>
#include <stdlib.h>
 
struct BSTNode{
    int value;
    struct BSTNode *l, *r;
}

*root = NULL, *temp = NULL, *t2, *t1;
 
// extra functions delete1, inorder, preorder, postorder
void delete1();
void insert();
void delete();
void createBST();
void searchBST(struct BSTNode *t);
void searchBST1(struct BSTNode *t,int data);
int smallestNode(struct BSTNode *t);
int largestNode(struct BSTNode *t);
void inorder(struct BSTNode *t);
void preorder(struct BSTNode *t);
void postorder(struct BSTNode *t);
 
int flag = 1;

//delete method to delete a node
void delete1(struct BSTNode *t){
  int k;

  if ((t->l == NULL) && (t->r == NULL))
  {
      if (t1->l == t)
      {
          t1->l = NULL;
      }
      else
      {
          t1->r = NULL;
      }
      t = NULL;
      free(t);
      return;
  }
  else if ((t->r = NULL))
  {
      if (t1 == t)
      {
          root = t->l;
          t1 = root;
      }
      else if (t1->l == t)
      {
          t1->l = t->l;

      }
      else
      {
          t1->r = t->l;
      }
      t = NULL;
      free(t);
      return;
  }
  else if (t->l == NULL)
  {
      if (t1 == t)
      {
          root = t->r;
          t1 = root;
      }
      else if (t1->r == t)
          t1->r = t->r;
      else
          t1->l = t->r;
      t = NULL;
      free(t);
      return;
  }
  else if ((t->l != NULL) && (t->r != NULL))  
  {
      t2 = root;
      if (t->r != NULL)
      {
          k = smallestNode(t->r);
          flag = 1;
      }
      else
      {
          k =largestNode(t->l);
          flag = 2;
      }
      searchBST1(root, k);
      t->value = k;
  }

}

void insert(){
  createBST();
  if (root == NULL) 
      root = temp;
  else    
      searchBST(root);    
}

//delte method to print the new BST  
void delete(){
  int data;

  if (root == NULL)
  {
      printf("No elements in a tree to delete");
      return;
  }
  printf("Enter the data to be deleted : ");
  scanf("%d", &data);
  t1 = root;
  t2 = root;
  searchBST1(root, data);
}

//creates the BST and prints it out
void createBST(){
  int data;
  printf("Enter data of node to be inserted: ");
  scanf("%d", &data);
  temp = (struct BSTNode *)malloc(1*sizeof(struct BSTNode));
  temp->value = data;
  temp->l = temp->r = NULL;
}
 
//searches the BST  
void searchBST(struct BSTNode *t){
  if ((temp->value > t->value) && (t->r != NULL))
      searchBST(t->r);
  else if ((temp->value > t->value) && (t->r == NULL))
      t->r = temp;
  else if ((temp->value < t->value) && (t->l != NULL))
      searchBST(t->l);
  else if ((temp->value < t->value) && (t->l == NULL))
      t->l = temp;
}
 
//prints the BST inorder
void inorder(struct BSTNode *t){
  if (root == NULL)
  {
      printf("No elements in a tree to display");
      return;
  }
  if (t->l != NULL)    
      inorder(t->l);
  printf("%d -> ", t->value);
  if (t->r != NULL)    
      inorder(t->r);
}
 
//prints the BST preorder
void preorder(struct BSTNode *t){
  if (root == NULL)
  {
      printf("No elements in a tree to display");
      return;
  }
  printf("%d -> ", t->value);
  if (t->l != NULL)    
      preorder(t->l);
  if (t->r != NULL)    
      preorder(t->r);
}
 
//prints the BST postorder
void postorder(struct BSTNode *t){
  if (root == NULL)
  {
      printf("No elements in a tree to display ");
      return;
  }
  if (t->l != NULL) 
      postorder(t->l);
  if (t->r != NULL) 
      postorder(t->r);
  printf("%d -> ", t->value);
}
 
//searched the BST 
void searchBST1(struct BSTNode *t, int data){
  if ((data>t->value))
  {
      t1 = t;
      searchBST1(t->r, data);
  }
  else if ((data < t->value))
  {
      t1 = t;
      searchBST1(t->l, data);
  }
  else if ((data = t-> value))
  {
      delete1(t);
  }
}
 
//finds smallest node
int smallestNode(struct BSTNode *t){
  t2 = t;
  if (t->l != NULL)
  {
      t2 = t;
      return(smallestNode(t->l));
  }
  else    
      return (t->value);
}
 
//finds largest node
int largestNode(struct BSTNode *t){
  if (t->r != NULL)
  {
      t2 = t;
      return(largestNode(t->r));
  }
  else    
      return(t->value);
}

//main method to print the BST tree
int main(void){
    int ch;

    printf("\n1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree\n");
    printf("3 - Inorder Traversal\n");
    printf("4 - Preorder Traversal\n");
    printf("5 - Postorder Traversal\n");
    printf("6 - Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch){
          case 1:    
              insert();
              break;
          case 2:    
              delete();
              break;
          case 3:    
              inorder(root);
              break;
          case 4:    
              preorder(root);
              break;
          case 5:    
              postorder(root);
              break;
          case 6:    
              exit(0);
          default :     
              printf("invalid choice");
              break;    
        }
    }
}


/*
  1 - Insert an element into tree
  2 - Delete an element from the tree
  3 - Inorder Traversal
  4 - Preorder Traversal
  5 - Postorder Traversal
  6 - Exit

  Enter your choice: 1
  Enter data of node to be inserted: 10

  Enter your choice: 1
  Enter data of node to be inserted: 11

  Enter your choice: 1
  Enter data of node to be inserted: 12

  Enter your choice: 1
  Enter data of node to be inserted: 9

  Enter your choice: 3
  9 -> 10 -> 11 -> 12 -> 
  Enter your choice: 4
  10 -> 9 -> 11 -> 12 -> 
  Enter your choice: 5
  9 -> 12 -> 11 -> 10 -> 
*/