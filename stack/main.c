#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int top;
  unsigned int capacity;
  int *array;
} Stack;

Stack *createStack(unsigned int capacity) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->array = (int *)malloc(sizeof(int) * capacity);
  stack->top = -1;
  return stack;
};

int is_empty(Stack *stack) { return stack->top == -1; }

int is_full(Stack *stack) { return stack->top + 1 == stack->capacity; }

void push(Stack *stack, int value) {
  if (is_full(stack))
    return;

  stack->array[++stack->top] = value;
}

void pop(Stack *stack) {
  if (is_empty(stack))
    return;
  stack->top--;
}

int peek(Stack *stack) {
  if (is_empty(stack))
    return 0;

  return stack->array[stack->top];
}

int main(int argc, char *argv[]) {
  Stack *stack = createStack(3);

  push(stack, 10);
  push(stack, 20);

  printf("%d\n", peek(stack));
  pop(stack);
  printf("%d", peek(stack));

  free(stack);
  return 0;
}
