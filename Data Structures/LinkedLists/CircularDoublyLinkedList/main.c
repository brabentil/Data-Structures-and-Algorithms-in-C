#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    struct node *next;
    int data;
    struct node *prev;
};

// Function prototypes
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main() {
    int option;
    struct node *start = NULL; // Initialize the list to be empty

    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                start = create_ll(start);
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
                start = delete_beg(start);
                break;
            case 6:
                start = delete_end(start);
                break;
            case 7:
                start = delete_node(start);
                break;
            case 8:
                start = delete_list(start);
                printf("\n CIRCULAR DOUBLY LINKED LIST DELETED");
                break;
        }
    } while (option != 9);

    return 0;
}

// Function to create a circular doubly linked list
struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);

    while (num != -1) {
        // Allocate memory for a new node
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL) {
            // If the list is empty, make the new node the start and set it as its own neighbor
            new_node->prev = new_node;
            new_node->next = new_node;
            start = new_node;
        } else {
            // Find the last node and update its neighbors
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            new_node->prev = ptr;
            ptr->next = new_node;
            new_node->next = start;
            start->prev = new_node;
        }

        printf("\n Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

// Function to display the circular doubly linked list
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;

    if (start == NULL) {
        printf("\n List is empty");
        return start;
    }

    do {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);

    return start;
}

// Function to insert a node at the beginning of the list
struct node *insert_beg(struct node *start) {
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL) {
        // If the list is empty, make the new node the start and set it as its own neighbor
        new_node->prev = new_node;
        new_node->next = new_node;
        start = new_node;
    } else {
        // Find the last node and update its neighbors
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        new_node->prev = ptr;
        ptr->next = new_node;
        new_node->next = start;
        start->prev = new_node;
        start = new_node; // Update the start to point to the new node
    }

    return start;
}

// Function to insert a node at the end of the list
struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;

    if (start == NULL) {
        return insert_beg(start);
    }

    printf("\n Enter the data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;

    while (ptr->next != start)
        ptr = ptr->next;

    new_node->prev = ptr;
    ptr->next = new_node;
    new_node->next = start;
    start->prev = new_node;

    return start;
}

// Function to delete a node from the beginning of the list
struct node *delete_beg(struct node *start) {
    struct node *ptr, *temp;

    if (start == NULL) {
        printf("\n List is empty");
        return start;
    }

    if (start->next == start) {
        // If there is only one node in the list, set start to NULL
        free(start);
        start = NULL;
    } else {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;

        ptr->next = start->next;
        temp = start;
        start = start->next;
        start->prev = ptr;
        free(temp);
    }

    return start;
}

// Function to delete a node from the end of the list
struct node *delete_end(struct node *start) {
    struct node *ptr, *temp;

    if (start == NULL) {
        printf("\n List is empty");
        return start;
    }

    if (start->next == start) {
        // If there is only one node in the list, set start to NULL
        free(start);
        start = NULL;
    } else {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;

        ptr->prev->next = start;
        start->prev = ptr->prev;
        free(ptr);
    }

    return start;
}

// Function to delete a given node from the list
struct node *delete_node(struct node *start) {
    struct node *ptr;
    int val;



    if (start == NULL) {
        printf("\n List is empty");
        return start;
    }

    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);

    if (ptr->data == val) {
        start = delete_beg(start);
        return start;
    } else {
        while (ptr->data != val && ptr->next != start)
            ptr = ptr->next;

        if (ptr->data == val) {
            // Found the node with the given value
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        } else {
            printf("\n Node with value %d not found", val);
        }
        return start;
    }
}

// Function to delete the entire circular doubly linked list
struct node *delete_list(struct node *start) {
    struct node *ptr, *temp;
    ptr = start;

    if (start == NULL) {
        printf("\n List is already empty");
        return start;
    }

    do {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    } while (ptr != start);

    start = NULL; // Set start to NULL since the list is empty
    return start;
}
