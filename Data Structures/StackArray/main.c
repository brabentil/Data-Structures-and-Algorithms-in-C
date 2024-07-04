#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

int stack[MAX], top=-1;

void push(int stack[], int val);
int pop (int stack[]);
int peek(int stack[]);
void display (int stack[]);


int main() {
    int option,val;

    do {
        printf("*** Main Menu *** \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your option:\n");
        scanf("%d",&option);

        switch (option){
            case 1 :
                printf("Enter the value to be pushed onto the stack:\n");
                scanf("%d",&val);
                push(stack,val);
                break;
            case 2:
                val = pop(stack);
                if(val != -1){
                    printf("The value popped is :%d \n",val);
                }
                break;
            case 3:
                val = peek(stack);
                if(val != -1){
                    printf("The value at the top of the stack is :%d\n",val);
                }
                break;
            case 4:
                display(stack);
                break;
        }
    }while(option != 5);

    return 0;
}
void push(int stack[], int val){
    if(top == MAX-1){
        printf("\nSTACK OVERFLOW!\n");

    }else{
        top ++;
        stack[top] = val;
    }
}
int pop (int stack[]){
    int val;
    if (top == -1){
        printf("\nSTACK UNDERFLOW\n");
        return -1;
    }
    else {
        val = stack[top];
        top--;
    }
    return val;
}
int peek(int stack[]){

    if (top == -1){
        printf("\nTHE STACK IS EMPTY\n");
    }
    else {

    }
    return (stack[top]);

}
void display (int stack[]){
    int i;
    if (top == -1){
        printf("\nTHE STACK IS EMPTY\n");
    }
    else {
        for (i = top; i >= 0; i--){
            printf("\n%d\n",stack[i]);
    }
    }
}

