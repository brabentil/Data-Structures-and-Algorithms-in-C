#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *start = NULL; // Global pointer to the start of the circular doubly linked list.

// Function prototypes
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                start = create_cll(start);
                printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_before(start);
                break;
            case 10:
                start = delete_after(start);
                break;
            case 11:
                start = delete_list(start);
                printf("\n CIRCULAR DOUBLY LINKED LIST DELETED");
                break;
        }
    } while (option != 12);

    return 0;
}

// Function to create a circular doubly linked list
struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = new_node; // Point to itself in a circular list.
            new_node->data = num;
            new_node->next = new_node; // Point to itself in a circular list.
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->prev = ptr->prev; // Update previous of new node
            new_node->next = ptr;       // Update next of new node
            ptr->prev->next = new_node; // Update next of previous node
            ptr->prev = new_node;       // Update previous of the current node
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

// Function to display the circular doubly linked list
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    do
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != start); // Continue until we reach the start again.
    return start;
}

// Function to insert a node at the beginning of the circular doubly linked list
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = start->prev; // Update previous of new node
    new_node->next = start;       // Update next of new node
    start->prev->next = new_node; // Update next of the last node
    start->prev = new_node;       // Update previous of the first node
    start = new_node;             // Update start to the new node
    return start;
}

// Function to insert a node at the end of the circular doubly linked list
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    new_node->prev = ptr;         // Update previous of new node
    new_node->next = start;       // Update next of new node
    ptr->next->prev = new_node;   // Update previous of the first node
    ptr->next = new_node;         // Update next of the last node
    return start;
}

// Function to insert a node before a given node in the circular doubly linked list
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->prev = ptr->prev;     // Update previous of new node
    new_node->next = ptr;           // Update next of new node
    ptr->prev->next = new_node;     // Update next of previous node
    ptr->prev = new_node;           // Update previous of the current node
    if (ptr == start)               // If the node before which we insert is the start node, update start.
        start = new_node;
    return start;
}

// Function to insert a node after a given node in the circular doubly linked list
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->prev = ptr;           // Update previous of new node
    new_node->next = ptr->next;     // Update next of new node
    ptr->next->prev = new_node;     // Update previous of the node after which we insert
    ptr->next = new_node;           // Update next of the current node
    return start;
}

// Function to delete a node from the beginning of the circular doubly linked list
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = ptr->prev;     // Update previous of the new start node
    ptr->prev->next = start;     // Update next of the last node
    free(ptr);
    return start;
}

// Function to delete a node from the end of the circular doubly linked list
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->prev->next = start;     // Update next of the last node
    start->prev = ptr->prev;     // Update previous of the start node
    free(ptr);
    return start;
}

// Function to delete a node before a given node in the circular doubly linked list
struct node *delete_before(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    temp = ptr->prev;
    temp->prev->next = ptr;     // Update next of previous node
    ptr->prev = temp->prev;     // Update previous of the current node
    if (temp == start)          // If the node before which we delete is the start node, update start.
        start = ptr;
    free(temp);
    return start;
}

// Function to delete a node after a given node in the circular doubly linked list
struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = temp->next;     // Update next of the current node
    temp->next->prev = ptr;     // Update previous of the node after which we delete
    free(temp);
    return start;
}

// Function to delete the entire circular doubly linked list
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        start = delete_beg(start); // Delete from the beginning until we reach the original start node.
        ptr = start;
    }
    free(start); // Free the last remaining node.
    start = NULL; // Set start to NULL as the list is empty.
    return start;
}
