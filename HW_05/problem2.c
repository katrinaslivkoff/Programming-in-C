#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
  int data;
  struct BSTNode *left, *right;
};

struct BSTNode *root = NULL;

//creates the node to be inserted in tree
struct BSTNode* createNode(int data) {
  struct BSTNode *newNode;
  newNode = (struct BSTNode *) malloc(sizeof (struct BSTNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return(newNode);
}

//inserts the node into the tree
//if null, creates the node
//if the data is less than the new data, it is inserted left
//if the data is greater than, it is inserted right
void insertion(struct BSTNode **node, int data) {
  if (*node == NULL) {
    *node = createNode(data);
  } 
  else if (data < (*node)->data) {
    insertion(&(*node)->left, data);
  } 
  else if (data > (*node)->data) {
    insertion(&(*node)->right, data);
  }
}

//deletes the node
//tests if node equals, is less than, or greater than data
void deletion(struct BSTNode **node, struct BSTNode **parent, int data) {
  struct BSTNode *tempNode, *tempPar;

  if (*node == NULL)
          return;

  if ((*node)->data == data) {
    if (!(*node)->left && !(*node)->right) {
      if (parent) {
        if ((*parent)->left == *node){
          (*parent)->left = NULL;
        }
        else{
          (*parent)->right = NULL;
        }
        free(*node);
      } 
      else {
        free(*node);
        (*node) = NULL;
      }
    } 
    else if (!(*node)->right && (*node)->left) {
      if(parent==NULL){
        tempNode = *node;
        (*node) = (*node)->left;
        free(tempNode);
        return;			
      }
      tempNode = *node;
      (*parent)->right = (*node)->left;
      free(tempNode);
      *node = (*parent)->right;
    } 
    else if ((*node)->right && !(*node)->left) {
      if(parent == NULL){
        tempNode = *node;
        (*node) = (*node)->right;
        free(tempNode);
        return;
      }
      tempNode = *node;
      (*parent)->left = (*node)->right;
      free(tempNode);
      (*node) = (*parent)->left;
    } 
    else if (!(*node)->right->left) {
      tempNode = *node;
      (*node)->right->left = (*node)->left;
      (*parent)->left = (*node)->right;
      free(tempNode);
      *node = (*parent)->left;
    } 
    else {
      tempNode = (*node)->right;
      while (tempNode->left) {
        tempPar = tempNode;
        tempNode = tempNode->left;
      }
      tempPar->left = tempNode->right;
      tempNode->left = (*node)->left;
      tempNode->right =(*node)->right;
      free(*node);
      *node = tempNode;
    }
  } 
  else if (data < (*node)->data) {
    deletion(&(*node)->left, node, data);
  } 
  else if (data > (*node)->data) {
    deletion(&(*node)->right, node, data);
  }
}

//searches the BST to find a specific node
void searchBST(struct BSTNode *node, int data) {
  if (!node)
    return;
  else if (data < node->data) {
    searchBST(node->left, data);
  } else if (data > node->data) {
    searchBST(node->right, data);
  } else
    printf("data found: %d\n", node->data);
  return;

}

//traverses through the BST and prints out the data
void traversal(struct BSTNode *node) {
  if (node != NULL) {
    traversal(node->left);
    printf("%3d", node->data);
    traversal(node->right);
  }
  return;
}

//main method to ask for user's input to create the BST
int main() {
  int data, ch;
  while (1) {
    printf("\n1. Insertion in Binary Search Tree\n");
    printf("2. Deletion in Binary Search Tree\n");
    printf("3. Search Element in Binary Search Tree\n");
    printf("4. Inorder traversal\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        while (1) {
          printf("Enter your data: ");
          scanf("%d", &data);
          insertion(&root, data);
          printf("Enter 1 to continue insertion; 0 to end: ");
          scanf("%d", &ch);
          if (!ch)
            break;
          }
        break;
      case 2:
        printf("Enter your data: ");
        scanf("%d", &data);
        deletion(&root, NULL, data);
        break;
      case 3:
        printf("Enter value for data: ");
        scanf("%d", &data);
        searchBST(root, data);
        break;
      case 4:
        printf("Inorder Traversal:\n");
        traversal(root);
        printf("\n");
        break;
      case 5:
        exit(0);
      default:
        printf("incorrect option\n");
        break;
    }
  }
  return 0;

}

/*
  1. Insertion in Binary Search Tree
  2. Deletion in Binary Search Tree
  3. Search Element in Binary Search Tree
  4. Inorder traversal
  5. Exit
  Enter your choice: 1
  Enter your data: 1
  Enter 1 to continue insertion; 0 to end: 1
  Enter your data: 10
  Enter 1 to continue insertion; 0 to end: 1
  Enter your data: 5
  Enter 1 to continue insertion; 0 to end: 1
  Enter your data: 12
  Enter 1 to continue insertion; 0 to end: 0

  1. Insertion in Binary Search Tree
  2. Deletion in Binary Search Tree
  3. Search Element in Binary Search Tree
  4. Inorder traversal
  5. Exit
  Enter your choice: 2
  Enter your data: 5

  1. Insertion in Binary Search Tree
  2. Deletion in Binary Search Tree
  3. Search Element in Binary Search Tree
  4. Inorder traversal
  5. Exit
  Enter your choice: 4
  Inorder Traversal:
    1 10 12
*/