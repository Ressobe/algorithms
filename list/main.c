/* Hello everyone
 * Today I'm going to be writing an implementation of singly linked list
 * Linked lists are basic data structures that you will learn in computer
 * science Each node have value and pointer to the next node Head is a pointer
 * to first node in list , we have to known where to start :) Last node we can
 * call tail
 *
 * On lists we can do diffrent operations:
 *  - Search element
 *  - Insert element to beginning of list
 *  - Insert element to end of list
 *  - Insert element to specific postion
 *  - Remove element
 *  - Calculate length of list
 *
 * Tests
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *head = NULL;

int check_list_exist() {
  if (head == NULL)
    return 0;

  return 1;
}

Node *insert_end(int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
    return NULL;
  new_node->value = value;

  if (head == NULL) {
    head = new_node;
    new_node->next = NULL;
    return new_node;
  }

  Node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return new_node;
}

Node *insert_begin(int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  if (head == NULL) {
    head = new_node;
    new_node->next = NULL;
    return new_node;
  }

  new_node->next = head;
  head = new_node;
  return new_node;
}

int remove_element(int value) {
  if (!check_list_exist())
    return 0;

  if (head->value == value) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return 1;
  }

  Node *prev = head;
  Node *current = head->next;

  while (current->next != NULL && current->value != value) {
    prev = current;
    current = current->next;
  }

  if (current->value == value) {
    prev->next = current->next;
    free(current);
    return 1;
  }

  return 0;
}

int length() {
  Node *next_element = head;
  int len = 0;
  while (next_element != NULL) {
    next_element = next_element->next;
    len++;
  }
  return len;
}

Node *insert_position(int position, int value) {
  Node *current = head;
  int i = 1;

  if (position > length()) {
    printf("This position doesn't exist\n");
    return NULL;
  }

  while (i < position - 1 && current->next != NULL) {
    current = current->next;
    i++;
  }

  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
    return NULL;

  new_node->value = value;
  new_node->next = current->next;
  current->next = new_node;

  return new_node;
}

void print_list() {
  if (!check_list_exist()) {
    printf("List is empty\n");
    return;
  }

  Node *current = head;
  while (current->next != NULL) {
    printf("%d ----> ", current->value);
    current = current->next;
  }

  printf("%d\n", current->value);
}

int find(int value) {
  Node *current = head;
  int i = 1;
  while (current->next != NULL && current->value != value) {
    current = current->next;
    i++;
  }
  if (current->value == value) {
    return i;
  }
  return 0;
}

void clear_list() {
  if (!check_list_exist())
    return;

  Node *current = head;
  Node *temp;
  while (current->next != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }
  head = NULL;
}

int test() {
  for (int i = 1; i < 11; i++) {
    insert_end(i);
  }

  insert_end(30);
  if (find(30) != 11) {
    printf("A\n");
    return 0;
  }

  insert_position(3, 40);
  if (find(40) != 3) {
    printf("B\n");
    return 0;
  }

  remove_element(9);
  if (find(9) != 0) {
    printf("C\n");
    return 0;
  }

  return 1;
}

int length_recursion(Node *node) {
  if (node == NULL)
    return 0;

  return 1 + length_recursion(node->next);
}

void test2() {
  for (int i = 1; i < 11; i++) {
    insert_end(i);
  }
  length_recursion(head);
}

void pop() {
  if (head == NULL) {
    return;
  }
  Node *x = head;
  Node *y = x->next;
  if (y == NULL) {
    head = NULL;
    return;
  }

  while (x->next != NULL) {
    y = x;
    x = x->next;
  }
  y->next = NULL;
}

void print_menu() {
  printf("\nSingly Linked List \n");
  printf("---------------------------------\n");
  printf("1. Print list\n");
  printf("2. Insert element to beginning of list\n");
  printf("3. Insert element to end of list\n");
  printf("4. Insert element to specific postition\n");
  printf("5. Remove element\n");
  printf("6. Remove list\n");
  printf("7. Get length of the list\n");
  printf("8. Run test (removes your current list)\n");
  printf("9. Quit\n");
  printf(":  ");
}

int main(int argc, char *argv[]) {
  test2();
  return 0;
}
// int main(int argc, char *argv[]) {
//   int choice = 1;
//   int value;
//   int pos;

//   while (choice != 9) {
//     print_menu();
//     scanf("%d", &choice);
//     system("clear");

//     switch (choice) {
//     case 1:
//       print_list();
//       break;

//     case 2:
//       printf("Value for new node (number): ");
//       scanf("%d", &value);
//       insert_begin(value);
//       break;

//     case 3:
//       printf("Value for new node (number): ");
//       scanf("%d", &value);
//       insert_end(value);
//       break;

//     case 4:
//       printf("Value for new node (number): ");
//       scanf("%d", &value);

//       printf("Postition to insert (number): ");
//       scanf("%d", &pos);

//       insert_position(pos, value);
//       break;

//     case 5:
//       printf("Value of the node to delete (number): ");
//       scanf("%d", &value);
//       remove_element(value);
//       break;

//     case 6:
//       clear_list();
//       break;

//     case 7:
//       printf("Length: %d\n", length());
//       break;

//     case 8:
//       clear_list();
//       if (test()) {
//         printf("Test pass\n");
//       } else {

//         printf("Test fail\n");
//       }
//       clear_list();
//       break;

//     case 9:
//       choice = 9;
//       break;

//     case 10:
//       printf("Length recursion: %d\n", length_recursion(head));
//       break;

//     case 11:
//       pop();
//       printf("Pop \n");
//       break;
//     }
//   }
//   clear_list();
//   return 0;
// }
