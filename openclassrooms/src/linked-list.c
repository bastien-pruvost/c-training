#include "linked-list.h"

#include <stdio.h>
#include <stdlib.h>

// Create a new linked list (heap allocation)
LinkedList *createList(void) {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (!list) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  list->head = NULL;
  list->size = 0;
  return list;
}

// Create a new node (heap allocation)
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insert at the beginning
int insertAtBeginning(LinkedList *list, int data) {
  Node *newNode = createNode(data);
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed\n");
    return -1;
  }
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
  return 0;
}

// Insert at the end
int insertAtEnd(LinkedList *list, int data) {
  Node *newNode = createNode(data);
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed\n");
    return -1;
  }
  if (list->head == NULL) {
    list->head = newNode;
  } else {
    Node *temp = list->head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  list->size++;
  return 0;
}

// Insert at a specific position
int insertAtPosition(LinkedList *list, int data, int position) {
  if (position < 0 || position > list->size) {
    fprintf(stderr, "Invalid position\n");
    return -1;
  }
  if (position == 0) {
    return insertAtBeginning(list, data);
  }
  Node *newNode = createNode(data);
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed\n");
    return -1;
  }
  Node *temp = list->head;
  for (int i = 0; i < position - 1; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  list->size++;
  return 0;
}

// Delete from the beginning
int deleteFromBeginning(LinkedList *list) {
  if (list->head == NULL) {
    fprintf(stderr, "List is empty\n");
    return -1;
  }
  Node *temp = list->head;
  list->head = list->head->next;
  free(temp);
  list->size--;
  return 0;
}

// Delete from the end
int deleteFromEnd(LinkedList *list) {
  if (list->head == NULL) {
    fprintf(stderr, "List is empty\n");
    return -1;
  }
  if (list->head->next == NULL) {
    free(list->head);
    list->head = NULL;
  } else {
    Node *temp = list->head;
    while (temp->next->next) {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
  }
  list->size--;
  return 0;
}

// Delete from a specific position
int deleteFromPosition(LinkedList *list, int position) {
  if (position < 0 || position >= list->size) {
    fprintf(stderr, "Invalid position\n");
    return -1;
  }
  if (position == 0) {
    return deleteFromBeginning(list);
  }
  Node *temp = list->head;
  for (int i = 0; i < position - 1; i++) {
    temp = temp->next;
  }
  Node *toDelete = temp->next;
  temp->next = toDelete->next;
  free(toDelete);
  list->size--;
  return 0;
}

// Print the linked list
void printList(LinkedList *list) {
  Node *temp = list->head;
  while (temp) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Free the entire linked list
void freeList(LinkedList *list) {
  Node *temp = list->head;
  while (temp) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }
  free(list);
}
