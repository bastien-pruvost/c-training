#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  struct Node *head;
  int size;
} LinkedList;

LinkedList *createList(void);
Node *createNode(int data);
int insertAtBeginning(LinkedList *list, int data);
int insertAtEnd(LinkedList *list, int data);
int insertAtPosition(LinkedList *list, int data, int position);
int deleteFromBeginning(LinkedList *list);
int deleteFromEnd(LinkedList *list);
int deleteFromPosition(LinkedList *list, int position);
void printList(LinkedList *list);
void freeList(LinkedList *list);

#endif
