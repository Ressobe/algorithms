#include <stdio.h>
#include <stdlib.h>


typedef struct {
  void *next;
  int value;
} Node;


Node *head = NULL;

// add node
Node *addNode(int value) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL)
    return NULL;

  if (head == NULL) {
    node->value = value;
    node->next = NULL;
    head = node;
  }
  else {
    node->value = value;
    node->next = head;
    head = node;
  }
  return node;
}


void printList() {
  Node *current = head;
  while (current != NULL) {
    printf("%d->", current->value);
    current = current->next;
  }
  printf("\n");
}

int removeNode(int value) {
  Node *current = head;
  Node *prev = head;

  if (head == NULL) {
    free(head);
  }

  while (current != NULL) {
    if (current->value == value) {
      if (current == head) {
        head = current->next;
      }
      else {
        prev->next = current->next;
        free(current);
        current = NULL;
      }
    }
  }

}


void printMenu() {

  printf("Singly Linked List \n");
  printf("====================== \n\n");

  printf("1. Add node to the list\n");
  printf("2. Remove node from the list\n");
  printf("3. Insert node to the list\n");
  printf("4. Print list\n");
  printf("5. Quit\n");
  printf(":");
}

int main() {

  int choice = 0;
  while (choice != 5) {
    printMenu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Value:");
        int value;
        scanf("%d", &value);
        addNode(value);
        break;

      case 2:
        // remove node
        break;

      case 3:
        // insert node
        break;
      case 4:
        printList();
        break;

      case 5:
        break;
    }
  }
  return 0;
}
