#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data);
void insertStart(Node** head, int data);
void removeStart(Node** head);
void displayList(Node* head);
void freeList(Node* head);

#endif