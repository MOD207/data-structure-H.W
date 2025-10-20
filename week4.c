#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void append(Node** head, Node** tail, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        *tail = new_node;
    } else {
        new_node->prev = *tail; 
        (*tail)->next = new_node; 
        *tail = new_node;      
    }
}
void freeListRecursive(Node* node) {

    if (node == NULL) {
        return;
    }

    Node* next_node = node->next;
    
    freeListRecursive(next_node);

    free(node);
}
void deleteAll(Node** head_ref, Node** tail_ref) {
    freeListRecursive(*head_ref);
    
    // Reset the list's pointers
    *head_ref = NULL;
    *tail_ref = NULL;
}

void insertAfter(Node** tail, Node* prev_node, int new_data) {

    if (prev_node == NULL) {
        printf("Error: 'prev_node' cannot be NULL.\n");
        return;
    }


    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    new_node->data = new_data;
    Node* next_node = prev_node->next;
    new_node->prev = prev_node;
    new_node->next = next_node;
    prev_node->next = new_node;

    if (next_node != NULL) {
        next_node->prev = new_node;
    } else {
        *tail = new_node;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    printf("1. Appending to list\n");
    append(&head, &tail, 10);
    append(&head, &tail, 20);
    append(&head, &tail, 30);

    printf("2. Inserting between elements\n");
    Node* node_20 = head->next;
    
    insertAfter(&tail, node_20, 25);

    insertAfter(&tail, tail, 40);
    printf("3. Deleting all elements\n");
    deleteAll(&head, &tail);
    printf("List deleted.\n");

    return 0;
}