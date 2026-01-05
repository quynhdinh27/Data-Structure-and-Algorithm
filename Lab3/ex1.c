#include <stdio.h>
#include <string.h>
#define CAPACITY 100
typedef struct Customer{
    char name[50];
    char wantItem[50];
    int wantQuantity;
} Customer;
typedef struct Queue{
    int front, back;
    Customer data[CAPACITY];
} Queue;

typedef struct Product{
    char name[50];
    float price;
    int quantity;
} Product;
void init(Queue *q, Product *p) {
    q->front =0;
    q->back =0;
    strcpy(p->name, ""); 
    p->quantity=0;
    p->price=0;
}
int length(Queue *q) {
    int l = q->back - q->front;
    return l;
}
void enqueue(Queue *q, Customer *c) {
    if(length(q)==CAPACITY) {
        printf("Full of customers");
   
    } 
    q->data[q->back] = *c;
    q->back++;
} 
void dequeue(Queue *q) {
    if(length(q)==0) {
        printf("No one");
    } 
        if(length(q)>1) {
            for(int i=1; i<length(q);i++) {
                q->data[i-1]=q->data[i];
            }
            q->back=q->back-1;
        }
    }

void displayProduct(Product *p) {
     printf("Product: %s | Price: %.2f | Stock: %d\n",
           p->name, p->price, p->quantity);
}

void displayQueue(Queue *q) {
     if (length(q) == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current queue:\n");
    for (int i = q->front; i < q->back; i++) {
        printf("%s wants %d of %s\n",
               q->data[i].name,
               q->data[i].wantQuantity,
               q->data[i].wantItem);
    }
}
int main() {
    Queue q;
    Product p;
    init(&q,&p);
    strcpy(p.name, "Phone");
    p.price = 500;
    p.quantity = 10;
    strcpy(p.name, "Tulip");
    p.price=20;
    p.quantity=60;
    Customer c1 = {"Alice", "Phone", 2};
    Customer c2 = {"Bob", "Phone", 4};
    Customer c3 ={"Fish","Tulip",9};


    enqueue(&q, &c1);
    enqueue(&q, &c2);
    enqueue(&q,&c3);

    displayProduct(&p);
    displayQueue(&q);

    printf("\nDequeuing...\n");
    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);

    return 0;

}
