#include <stdio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

void insert(int queue[], int val);
int delete_element(int queue[]);
int peek(int queue[]);
void display(int queue[]);

int main() {
    int option, val;
    do {
        printf("\n\n*** Main Menu ***\n\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &option);

        while (option < 1 || option > 5) {
            printf("Invalid Entry!\nRe-enter choice:\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Peek\n");
            printf("4. Display\n");
            printf("5. Exit\n");
            scanf("%d", &option);
        }

        switch (option) {
            case 1:
                printf("Enter the value to insert: \n");
                scanf("%d", &val);

                insert(queue, val);
                break;
            case 2:
                val = delete_element(queue);
                if (val == -1) {
                    printf("The queue is empty!\n");
                } else {
                    printf("The item deleted is: %d\n", val);
                }
                break;
            case 3:
                val = peek(queue);
                if (val == -1) {
                    printf("The queue is empty!\n");
                } else {
                    printf("The item at the front of the queue is : %d\n", val);
                }
                break;
            case 4:
                display(queue);
        }
    } while (option != 5);

    return 0;
}

void insert(int queue[], int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow!\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[front] = val;
    } else if (rear == MAX - 1) {
        rear = 0;
        queue[rear] = val;
    } else {
        rear++;
        queue[rear] = val;
    }
}

int delete_element(int queue[]) {
    int val;
    if (front == -1 && rear == -1) {
        return -1;
    } else {
        val = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            if (front == MAX - 1) {
                front = 0;
            } else {
                front++;
            }
        }
        return val;
    }
}

int peek(int queue[]) {
    if (front == -1 && rear == -1) {
        return -1;
    } else {
        return queue[front];
    }
}

void display(int queue[]) {
    if (front == -1) {
        printf("The queue is empty!\n");
    } else {
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                printf("%d \t", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d \t", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d \t", queue[i]);
            }
        }
    }
}
