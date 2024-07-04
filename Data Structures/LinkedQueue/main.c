#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the queue
struct node {
    int data;
    struct node *next;
};

// Structure for the queue
struct queue {
    struct node *front;
    struct node *rear;
};

struct queue *q; // Declare a global queue pointer

// Function to create an empty queue
void create_queue(struct queue *q) {
    q->rear = NULL;
    q->front = NULL;
}

// Function to insert an element into the queue
void insert(struct queue *q, int val) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL) {
        q->front = ptr;
        q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }
}

// Function to display the elements in the queue
void display(struct queue *q) {
    struct node *ptr;
    ptr = q->front;

    if (ptr == NULL) {
        printf("\n QUEUE IS EMPTY\n");
        return;
    }

    printf("\nQueue elements: ");
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to delete an element from the front of the queue
void delete_element(struct queue *q) {
    struct node *ptr;

    if (q->front == NULL) {
        printf("\n UNDERFLOW\n");
        return;
    } else {
        ptr = q->front;
        q->front = q->front->next;
        printf("\n The value being deleted is: %d\n", ptr->data);
        free(ptr);
    }
}

// Function to peek at the front element of the queue
int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("\n QUEUE IS EMPTY\n");
        return -1; // Placeholder for empty queue
    } else {
        return q->front->data;
    }
}

int main() {
    int val, option;
    q = (struct queue *)malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    create_queue(q);

    do {
        printf("\n ****MAIN MENU****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n Enter the number to insert in the queue: ");
                scanf("%d", &val);
                insert(q, val);
                break;
            case 2:
                delete_element(q);
                break;
            case 3:
                val = peek(q);
                if (val != -1)
                    printf("\n The value at the front of the queue is: %d\n", val);
                break;
            case 4:
                display(q);
                break;
        }
    } while (option != 5);

    // Free memory before exiting
    while (q->front != NULL) {
        delete_element(q);
    }
    free(q);

    return 0;
}
