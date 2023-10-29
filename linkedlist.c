#include "linkedlist.h"

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertStart(Node** head, int data) {
  Node* newNode = createNode(data);
  
  newNode->next = *head;
  *head = newNode;
}

void removeStart(Node** head) {
	Node* removeNode;

	removeNode = *head;
	*head = removeNode->next;
	
  free(removeNode);
}

void displayList(Node* head) {
  Node* temp = head;
  
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void freeList(Node* head) {
  Node* temp;
  
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}