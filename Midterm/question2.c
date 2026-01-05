#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 100

typedef struct Stack {
int data[CAPACITY];
int top;
} Stack;

void init(Stack *s) {
s->top = -1;
}

bool isEmpty(Stack *s) {
return s->top == -1;
}

void push(Stack *s, int value) {
s->data[++s->top] = value;
}

int pop(Stack *s) {
return s->data[s->top--];
}

void decToBinary(int n, Stack *s) {
init(s);
while (n > 0) {
push(s, n % 2);
n /= 2;
}
}

void display(Stack *s) {
printf("Binary: ");
while (!isEmpty(s)) {
printf("%d", pop(s));
}
printf("\n");
}

int main() {
Stack *s = (Stack*)malloc(sizeof(Stack));

decToBinary(13, s);
display(s);

free(s);
return 0;


}
