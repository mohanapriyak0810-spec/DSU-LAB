#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void insert(struct node **head, int x, int pos) {
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = x;

    // Insert at position 1
    if (pos == 1) {
        newnode->prev = NULL;
        newnode->next = *head;

        if (*head != NULL) {
            (*head)->prev = newnode;
        }

        *head = newnode;
        return;
    }

    // Insert at position > 1
    struct node *temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

void display(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    insert(&head, 10, 1);
    insert(&head, 20, 2);
    insert(&head, 30, 3);

    display(head);

    printf("Code Completed!\n");

    return 0;
}

