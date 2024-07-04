#include <stdio.h>
#include <conio.h>
#include <malloc.h>
/*
1. Start
2. Initialize variables:
   - n (number of players)
   - k (every kth player gets eliminated)
   - i (loop counter)
   - count (number of remaining players)
3. Prompt the user to enter the number of players (n)
4. Prompt the user to enter the value of k
5. Create a circular linked list to represent the players:
   a. Create the first player node (start) and set its player_id to 1
   b. Set ptr to start
   c. For i = 2 to n:
      i. Create a new player node (new_node) and set its player_id to i
      ii. Link the new player node to the end of the circular list (ptr->next = new_node)
      iii. Update ptr to the new player node (ptr = new_node)
   d. Make the circular list by linking the last player to the first player (new_node->next = start)
6. Eliminate players until only one player remains:
   a. For count = n to 1 (loop decremented after each elimination):
      i. For i = 1 to k - 1 (skip k-1 players):
         - Update ptr to the next player (ptr = ptr->next)
      ii. Remove the kth player by updating the next pointer (ptr->next = ptr->next->next)
7. Announce the winner (the remaining player):
   - Print "The Winner is Player [player_id]"
8. Wait for user input before exiting
9. End

*/

// Define a struct to represent a player in the game
struct node
{
    int player_id;
    struct node
            *next;
};

struct node* start, *ptr, *new_node;

int main()
{
    int n, k, i, count;

    // Prompt the user to enter the number of players
    printf("\n Enter the number of players : ");
    scanf("%d", &n);

    // Prompt the user to enter the value of k (every kth player gets eliminated)
    printf("\n Enter the value of k (every kth player gets eliminated): ");
    scanf("%d", &k);

    // Create a circular linked list containing all the players

    // Allocate memory for the first player
    start = malloc(sizeof(struct node));
    start->player_id = 1;
    ptr = start;

    // Create nodes for the remaining players and link them in a circular manner
    for (i = 2; i <= n; i++)
    {
        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next = start;
        ptr = new_node;
    }

    // Eliminate players until there's only one left
    for (count = n; count > 1; count--)
    {
        for (i = 0; i < k - 1; ++i) {
            ptr = ptr->next;
        }
         // Remove the eliminated player from the circular listA
        ptr->next = ptr->next->next;
    }

    // Announce the winner
    printf("\n The Winner is Player %d", ptr->player_id);

    // Wait for user input before exiting
    getch();

    return 0;
}
